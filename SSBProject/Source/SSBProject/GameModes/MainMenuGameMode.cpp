// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameMode.h"

void AMainMenuGameMode::SetGameCharacterConfiguration(const TArray<int32>& NewTargetPlayerCount, int32 NewAICharacterCount)
{
	TargetPlayerCount = NewTargetPlayerCount;
	AICharacterCount = NewAICharacterCount;
}

const TArray<int32>& AMainMenuGameMode::GetTargetPlayerCount()
{
	return TargetPlayerCount;
}

int32 AMainMenuGameMode::GetAICharacterCount()
{
	return AICharacterCount;
}
