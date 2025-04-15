// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "MainMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SSBPROJECT_API AMainMenuGameMode : public AGameMode
{
	GENERATED_BODY()
	
public:
	void SetGameCharacterConfiguration(const TArray<int32>& NewTargetPlayerCount, int32 NewAICharacterCount);

	const TArray<int32>& GetTargetPlayerCount();

	int32 GetAICharacterCount();
	
private:
	// ���� �� �� �ִ� �÷��̾� ��
	TArray<int32> TargetPlayerCount;

	// ������ AI ĳ���� ��
	int32 AICharacterCount;
};
