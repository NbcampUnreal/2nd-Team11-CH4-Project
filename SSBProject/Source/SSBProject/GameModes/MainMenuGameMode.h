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
	// 시작 할 수 있는 플레이어 수
	TArray<int32> TargetPlayerCount;

	// 스폰될 AI 캐릭터 수
	int32 AICharacterCount;
};
