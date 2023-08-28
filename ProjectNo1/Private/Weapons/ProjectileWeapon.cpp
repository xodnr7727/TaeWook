// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/ProjectileWeapon.h"
#include "Components/BoxComponent.h"
#include "Engine/Classes/Particles/ParticleSystemComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AProjectileWeapon::AProjectileWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Particle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particle"));
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	ArrowBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ArrowBox"));

	SetRootComponent(Mesh);

	// 몬스터 객체와 충돌하는 프로파일 적용
	ArrowBox->SetCollisionProfileName(TEXT("PlayerAttack"));
	ArrowBox->SetBoxExtent(FVector(20.f, 20.f, 20.f));

	ArrowBox->SetupAttachment(Mesh);
	Particle->SetupAttachment(Mesh);

	Mesh->SetRelativeRotation(FRotator(-90.f, -90.f, 0.f));

}

// Called when the game starts or when spawned
void AProjectileWeapon::BeginPlay()
{
	Super::BeginPlay();

	ArrowBox->OnComponentBeginOverlap.AddDynamic(this, &AProjectileWeapon::ArrowBeginOverlap);
	ArrowBox->OnComponentEndOverlap.AddDynamic(this, &AProjectileWeapon::ArrowEndOverlap);
	
}

// Called every frame
void AProjectileWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Overlap이 시작할 때 호출되는 함수
void AProjectileWeapon::ArrowBeginOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult& SweepResult)
{
	FDamageEvent DamageEvent;

	// 여기서 OtherActor는 ProjectileArrow와 충돌한 객체, 즉 몬스터 객체이다
	float fDamage = OtherActor->TakeDamage(30.f, DamageEvent, GetWorld()->GetFirstPlayerController(), this);

	this->Destroy();
}

// Overlap이 끝날 때 호출되는 함수
void AProjectileWeapon::ArrowEndOverlap(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}
