// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void USlashOverlay::SetHealthBarPercent(float Percent)
{
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetStaminaBarPercent(float Percent)
{
	if (StaminaProgressBar)
	{
		StaminaProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetExperienceBarPercent(float Percent)
{
	if (ExProgressBar)
	{
		ExProgressBar->SetPercent(Percent);
	}
}


void USlashOverlay::SetGold(int32 Gold)
{
	if (GoldText)
	{
		const FString String = FString::Printf(TEXT("%'d"), Gold);
		FNumberFormattingOptions FormatOptions;
		FormatOptions.UseGrouping = true; //천 단위로 구분 출력
		const FText Text = FText::AsNumber(Gold, &FormatOptions);
		GoldText->SetText(Text);
	}
}

/*void USlashOverlay::SetSouls(int32 Souls)
{
	if (SoulsText)
	{
		const FString String = FString::Printf(TEXT("%d"), Souls);
		const FText Text = FText::FromString(String);
		SoulsText->SetText(Text);
	}
}*/