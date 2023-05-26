// Copyright Epic Games, Inc. All Rights Reserved.

#include "ProjectNo1Character.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "Animation/AnimInstance.h"
#include "Animation/AnimMontage.h"
#include "Kismet/GameplayStatics.h"
#include "Components/BoxComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Interfaces/HitInterface.h"
#include "Components/AttributeComponent.h"
#include "Item.h"
#include "Weapons/Weapon.h"
#include "HUD/MyProNo1HUD.h"
#include "HUD/SlashOverlay.h"
#include "Soul.h"
#include "Items/Treasure.h"

//////////////////////////////////////////////////////////////////////////
// AProjectNo1Character

AProjectNo1Character::AProjectNo1Character()
{
	PrimaryActorTick.bCanEverTick = true;
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rate for input
	TurnRateGamepad = 50.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f); // ...at this rotation rate

	GetMesh()->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	GetMesh()->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_Visibility, ECollisionResponse::ECR_Block);
	GetMesh()->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
	GetMesh()->SetGenerateOverlapEvents(true);

	// Note: For faster iteration times these variables, and many more, can be tweaked in the Character Blueprint
	// instead of recompiling to adjust them
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 800.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named ThirdPersonCharacter (to avoid direct content references in C++)

	SprintSpeedMultiplier = 1.5f; //달리기 배속

}

void AProjectNo1Character::GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter)
{
	Super::GetHit_Implementation(ImpactPoint, Hitter);

	SetWeaponCollisionEnabled(ECollisionEnabled::NoCollision);
	ActionState = EActionState::EAS_HitReaction;
}

void AProjectNo1Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Attributes && SlashOverlay)
	{
		Attributes->RegenHealth(DeltaTime);
		Attributes->RegenStamina(DeltaTime);
		SlashOverlay->SetHealthBarPercent(Attributes->GetHealthPercent());
		SlashOverlay->SetStaminaBarPercent(Attributes->GetStaminaPercent());
		SlashOverlay->SetExperienceBarPercent(Attributes->GetExperiencePercent());
	}
}

void AProjectNo1Character::SetOverlappingItem(AItem* Item)
{
	OverlappingItem = Item;
}

void AProjectNo1Character::AddEx(ASoul* Soul)
{
	if (Attributes && SlashOverlay)
	{
		Attributes->AddSouls(Soul->GetSouls());
		SlashOverlay->SetExperienceBarPercent(Attributes->GetExperiencePercent());
	}
}

void AProjectNo1Character::AddGold(ATreasure* Treasure)
{
	if (Attributes && SlashOverlay)
	{
		Attributes->AddGold(Treasure->GetGold());
		SlashOverlay->SetGold(Attributes->GetGold());
	}
}

void AProjectNo1Character::BeginPlay()
{
	Super::BeginPlay();

	Tags.Add(FName("EngageableTarget"));
	InitializeSlashOverlay();
}

void AProjectNo1Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AProjectNo1Character::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//PlayerInputComponent->BindAction("LMB", IE_Pressed, this, &AProjectNo1Character::LMBDown);
	//PlayerInputComponent->BindAction("LMB", IE_Released, this, &AProjectNo1Character::LMBUp);

	PlayerInputComponent->BindAction(FName("Attack"), IE_Pressed, this, &AProjectNo1Character::Attack);

	PlayerInputComponent->BindAction(FName("Block"), IE_Pressed, this, &AProjectNo1Character::RMKeyPressed);

	PlayerInputComponent->BindAxis("Move Forward / Backward", this, &AProjectNo1Character::MoveForward);
	PlayerInputComponent->BindAxis("Move Right / Left", this, &AProjectNo1Character::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn Right / Left Mouse", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("Turn Right / Left Gamepad", this, &AProjectNo1Character::TurnAtRate);
	PlayerInputComponent->BindAxis("Look Up / Down Mouse", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("Look Up / Down Gamepad", this, &AProjectNo1Character::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AProjectNo1Character::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AProjectNo1Character::TouchStopped);

	PlayerInputComponent->BindAction("Equip", IE_Pressed, this, &AProjectNo1Character::EKeyPressed);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &AProjectNo1Character::Sprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &AProjectNo1Character::StopSprinting);

	PlayerInputComponent->BindAction(FName("Dive"), IE_Pressed, this, &AProjectNo1Character::Dive);

	PlayerInputComponent->BindAction(FName("NeckSkill"), IE_Pressed, this, &AProjectNo1Character::OnNeckSkillPressed);


}

void AProjectNo1Character::OnNeckSkillPressed()
{
	if (CanNeckSkill())
	{
		PlayNeckSkillMontage();
		ActionState = EActionState::EAS_NeckSkillDo;
	}
}

void AProjectNo1Character::EquipNeck(AWeapon* NewNeck)
{
	EquippedNeck = NewNeck;
}

void AProjectNo1Character::Jump()
{
	if (IsUnoccupied())
	{
		Super::Jump();
	}

}

void AProjectNo1Character::Sprint()
{
	if (!HasEnoughStamina()) return;
		GetCharacterMovement()->MaxWalkSpeed *= SprintSpeedMultiplier;
	
}

void AProjectNo1Character::StopSprinting()
{
	GetCharacterMovement()->MaxWalkSpeed /= SprintSpeedMultiplier;


}

float AProjectNo1Character::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	HandleDamage(DamageAmount);
	SetHUDHealth();
	return DamageAmount;
}

void AProjectNo1Character::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
	Jump();
}

void AProjectNo1Character::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
	StopJumping();
}

void AProjectNo1Character::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void AProjectNo1Character::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * TurnRateGamepad * GetWorld()->GetDeltaSeconds());
}

void AProjectNo1Character::MoveForward(float Value)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	//if ((AnimInstance->Montage_IsPlaying(AttackMontage))) return; //공격중일때 이동 멈춤
	if ((AnimInstance->Montage_IsPlaying(ShieldMontage))) return;
	else if ((AnimInstance->Montage_IsPlaying(EquipUnEquipMontage))) return;
	else if ((AnimInstance->Montage_IsPlaying(HitReactMontage))) return;

	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AProjectNo1Character::MoveRight(float Value)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	//if ((AnimInstance->Montage_IsPlaying(AttackMontage))) return; //공격중일때 이동 멈춤
	if((AnimInstance->Montage_IsPlaying(ShieldMontage))) return;
	else if ((AnimInstance->Montage_IsPlaying(EquipUnEquipMontage))) return;
	else if ((AnimInstance->Montage_IsPlaying(HitReactMontage))) return;

	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AProjectNo1Character::EKeyPressed()
{
	AWeapon* OverlappingWeapon = Cast<AWeapon>(OverlappingItem);
	if (OverlappingWeapon)
	{
		if (EquippedWeapon)
		{
			EquippedWeapon->Destroy();
		}
		EquipWeapon(OverlappingWeapon);
	}
	else
	{
		if (CanDisarm())
		{
			Disarm();
		}
		else if (CanArm())
		{
			Arm();
		}
	}
}

void AProjectNo1Character::RMKeyPressed()
{
	if (CanBlock())
	{
		DisBlock();
	}
}

void AProjectNo1Character::IfAttack()
{
	if (ActionState == EActionState::EAS_Unoccupied)
	{
		Attack();
		ActionState = EActionState::EAS_Attacking;
	}
}

void AProjectNo1Character::EquipWeapon(AWeapon* Weapon)
{
	Weapon->Equip(GetMesh(), FName("SpineWeaponSocket"), this, this);
	CharacterState = ECharacterState::ECS_Unequipped;
	OverlappingItem = nullptr;
	EquippedWeapon = Weapon;
}

bool AProjectNo1Character::HasEnoughStamina()
{
	return Attributes && Attributes->GetStamina() > Attributes->GetDiveCost();
}

bool AProjectNo1Character::IsOccupied()
{
	return ActionState != EActionState::EAS_Unoccupied;
}

bool AProjectNo1Character::CanDisarm()
{
	return ActionState == EActionState::EAS_Unoccupied &&
		CharacterState != ECharacterState::ECS_Unequipped;
}

bool AProjectNo1Character::CanArm()
{
	return ActionState == EActionState::EAS_Unoccupied &&
		CharacterState == ECharacterState::ECS_Unequipped && EquippedWeapon;
}

bool AProjectNo1Character::CanBlock()
{
	return ActionState == EActionState::EAS_Unoccupied &&
		CharacterState != ECharacterState::ECS_Unequipped;
}

void AProjectNo1Character::Disarm()
{
	PlayEquip(FName("Unequip"));
	CharacterState = ECharacterState::ECS_Unequipped;
	ActionState = EActionState::EAS_EquippingWeapon;
}

void AProjectNo1Character::Arm()
{
	PlayEquip(FName("Equip"));
	CharacterState = ECharacterState::ECS_EquippedOneHandedWeapon;
	ActionState = EActionState::EAS_EquippingWeapon;
}

void AProjectNo1Character::DisBlock()
{
	Block(FName("Block1"));
	CharacterState = ECharacterState::ECS_EquippedOneHandedWeapon;
	ActionState = EActionState::EAS_Blocking;
}

void AProjectNo1Character::AsBlock()
{
	Block(FName("Block2"));
	CharacterState = ECharacterState::ECS_EquippedOneHandedWeapon;
	ActionState = EActionState::EAS_EndBlocking;
}

void AProjectNo1Character::AttachWeaponToBack()
{
	if (EquippedWeapon)
	{
		EquippedWeapon->AttachMeshToSocket(GetMesh(), FName("SpineWeaponSocket"));
	}
}

void AProjectNo1Character::AttachWeaponToHand()
{
	if (EquippedWeapon)
	{
		EquippedWeapon->AttachMeshToSocket(GetMesh(), FName("RightHandWeaponSocket"));
	}
}

void AProjectNo1Character::FinishEquipping()
{
	ActionState = EActionState::EAS_Unoccupied;
}

void AProjectNo1Character::HitReactEnd()
{
	ActionState = EActionState::EAS_Unoccupied;
}

bool AProjectNo1Character::IsUnoccupied()
{
	return ActionState == EActionState::EAS_Unoccupied;
}

void AProjectNo1Character::InitializeSlashOverlay()
{
	APlayerController* PlayerController = Cast<APlayerController>(GetController());
	if (PlayerController)
	{
		AMyProNo1HUD* MyProNo1HUD = Cast<AMyProNo1HUD>(PlayerController->GetHUD());
		if (MyProNo1HUD)
		{
			SlashOverlay = MyProNo1HUD->GetSlashOverlay();
			if (SlashOverlay && Attributes)
			{
				SlashOverlay->SetHealthBarPercent(Attributes->GetHealthPercent());
				SlashOverlay->SetStaminaBarPercent(1.f);
				SlashOverlay->SetExperienceBarPercent(Attributes->GetExperiencePercent());
			}
		}
	}
}

void AProjectNo1Character::SetHUDHealth()
{
	if (SlashOverlay && Attributes)
	{
		SlashOverlay->SetHealthBarPercent(Attributes->GetHealthPercent());
	}
}

void AProjectNo1Character::AttackEnd()
{
	ActionState = EActionState::EAS_Unoccupied;
}

void AProjectNo1Character::BlockEnd()
{
	ActionState = EActionState::EAS_Unoccupied;
}

void AProjectNo1Character::DiveEnd()
{
	Super::DiveEnd();

	ActionState = EActionState::EAS_Unoccupied;
}

void AProjectNo1Character::Attack() {
	Super::Attack();
	if (CanAttack())
	{
		PlayAttackMontage();
		ActionState = EActionState::EAS_Attacking;
	}
}

void AProjectNo1Character::Dive()
{
if (IsOccupied() || !HasEnoughStamina()) return;
	PlayDiveMontage();
	ActionState = EActionState::EAS_Dive;
	if (Attributes && SlashOverlay)
	{
		Attributes->UseStamina(Attributes->GetDiveCost());
		SlashOverlay->SetStaminaBarPercent(Attributes->GetStaminaPercent());
	}
}

bool AProjectNo1Character::CanAttack()
{
	return ActionState == EActionState::EAS_Unoccupied &&
		CharacterState != ECharacterState::ECS_Unequipped;
}

bool AProjectNo1Character::CanNeckSkill()
{
	return ActionState == EActionState::EAS_Unoccupied &&
		CharacterState != ECharacterState::ECS_Unequipped;
}

void AProjectNo1Character::Block(const FName& SectionName)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && ShieldMontage)
	{
		AnimInstance->Montage_Play(ShieldMontage);
		AnimInstance->Montage_JumpToSection(SectionName, ShieldMontage);
	}
}

void AProjectNo1Character::PlayEquip(const FName& SectionName)
{
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();
	if (AnimInstance && EquipUnEquipMontage)
	{
		AnimInstance->Montage_Play(EquipUnEquipMontage);
		AnimInstance->Montage_JumpToSection(SectionName, EquipUnEquipMontage);
	}
}

void AProjectNo1Character::EndAttacking()
{
	ActionState = EActionState::EAS_Unoccupied;
}

void AProjectNo1Character::EndBlocking()
{
	ActionState = EActionState::EAS_Unoccupied;
}


	
