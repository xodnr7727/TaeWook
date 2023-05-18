// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul.h"
#include "AttributeComponent.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class PROJECTNO1_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAttributeComponent();
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void RegenHealth(float DeltaTime);
	void RegenStamina(float DeltaTime);
protected:
	virtual void BeginPlay() override;


private:
	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		float Health;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		float MaxHealth;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		float Stamina;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		float MaxStamina;

		UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		float Experience;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		float MaxExperience;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		float DiveCost = 14.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		float HealthRegenRate = 4.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		float StaminaRegenRate = 8.f;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		int32 Gold;

	UPROPERTY(EditAnywhere, Category = "Actor Attributes")
		int32 Souls;

public:
	void ReceiveDamage(float Damage);
	float GetHealthPercent();
	bool IsAlive();
	void UseStamina(float StaminaCost);
	float GetStaminaPercent();
	float GetExperiencePercent();
	FORCEINLINE float GetDiveCost() const { return DiveCost; }
	FORCEINLINE float GetStamina() const { return Stamina; }
	void AddSouls(int32 NumberOfSouls);
	void AddGold(int32 AmountOfGold);
	void AddEx(float DropEx);
	FORCEINLINE int32 GetGold() const { return Gold; }
	FORCEINLINE float GetExperience() const { return Experience; }
	FORCEINLINE int32 GetSouls() const { return Souls; }

};
