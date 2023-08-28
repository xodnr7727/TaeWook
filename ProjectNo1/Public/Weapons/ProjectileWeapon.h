// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectileWeapon.generated.h"

class UBoxComponent;
class UStaticMeshComponent;
class UParticleSystemComponent;
class UProjectileMovementComponent;
UCLASS()
class PROJECTNO1_API AProjectileWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectileWeapon();

	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(Category = Mesh, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Mesh;

	UPROPERTY(Category = Collision, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UBoxComponent* ArrowBox;

	UPROPERTY(Category = Particle, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UParticleSystemComponent* Particle;

	UPROPERTY(Category = Projectile, VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* Movement;

public:
	// 충돌이 시작할시에 호출되는 델리게이트에 등록하는 함수
	UFUNCTION()
	void ArrowBeginOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
		bool bFromSweep, const FHitResult& SweepResult);

	// 충돌이 종료될시에 호출되는 델리게이트에 등록하는 함수
	UFUNCTION()
	void ArrowEndOverlap(UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
};
