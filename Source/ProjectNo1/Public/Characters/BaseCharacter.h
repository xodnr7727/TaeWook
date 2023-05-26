#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/HitInterface.h"
#include "BaseCharacter.generated.h"

class AWeapon;
class UAttributeComponent;
class UAnimMontage;

UCLASS()
class PROJECTNO1_API ABaseCharacter : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;
	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	virtual void Attack();
	virtual void Die();
	void DirectionalHitReact(const FVector& ImpactPoint);

	/**
	* Play montage functions
	*/

	virtual void HandleDamage(float DamageAmount);
	void PlayHitSound(const FVector& ImpactPoint);
	void SpawnHitParticles(const FVector& ImpactPoint);
	void DisableCapsule();

	virtual bool CanAttack();
	virtual bool CanNeckSkill();
	bool IsAlive();
	void PlayHitReactMontage(const FName& SectionName);
	virtual int32 PlayAttackMontage();
	virtual int32 PlayDeathMontage();
	virtual void PlayDiveMontage();
	virtual void PlayNeckSkillMontage();
	void StopAttackMontage();

	void SpawnEffect(const FVector& ImpactPoint);

	FVector GetWeaponTraceEndLocation() const;

	UFUNCTION(BlueprintCallable)
		FVector GetTranslationWarpTarget();

	UFUNCTION(BlueprintCallable)
		FVector GetRotationWarpTarget();

	UFUNCTION(BlueprintCallable)
	virtual void AttackEnd(); 

	UFUNCTION(BlueprintCallable)
	virtual void BlockEnd(); 

	UFUNCTION(BlueprintCallable)
		virtual void DiveEnd(); 

	UFUNCTION(BlueprintCallable)
		void SetWeaponCollisionEnabled(ECollisionEnabled::Type CollisionEnabled);

	UPROPERTY(VisibleAnywhere, Category = Weapon)
		AWeapon* EquippedWeapon;

	UPROPERTY(VisibleAnywhere, Category = Weapon)
	    AWeapon* EquippedNeck;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		UAttributeComponent* Attributes;

	UPROPERTY(BlueprintReadOnly, Category = Combat)
		AActor* CombatTarget;

	UPROPERTY(EditAnywhere, Category = Combat)
		double WarpTargetDistance = 75.f;

	UPROPERTY(EditDefaultsOnly, Category = Combat)
		UAnimMontage* AttackMontage;

	UPROPERTY(EditDefaultsOnly, Category = Combat)
		UAnimMontage* HitReactMontage;

	UPROPERTY(EditDefaultsOnly, Category = Combat)
		UAnimMontage* NeckSkillMontage;

	UPROPERTY(EditDefaultsOnly, Category = Combat)
		UAnimMontage* DeathMontage;

	UPROPERTY(EditDefaultsOnly, Category = Combat)
		UAnimMontage* DiveMontage;

	UPROPERTY(EditAnywhere, Category = Combat)
		TArray<FName> AttackMontageSections;

	UPROPERTY(EditAnywhere, Category = Combat)
		TArray<FName> DeathMontageSections;
	/*
	* Components
	*/

private:
	void PlayMontageSection(UAnimMontage* Montage, const FName& SectionName);
	int32 PlayRandomMontageSection(UAnimMontage* Montage, const TArray<FName>& SectionNames);

	UPROPERTY(EditAnywhere, Category = Combat)
		USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = Combat)
		UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, Category = Combat)
		UParticleSystem* WeaponParticles;
};