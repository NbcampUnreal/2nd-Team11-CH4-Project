// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "FighterGamemode.generated.h"

/**
 * 
 */
UCLASS()
class SSBPROJECT_API AFighterGamemode : public AGameMode
{
	GENERATED_BODY()
	
public:
	AFighterGamemode();

	virtual void InitGameState() override;

protected:
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

public:
	UFUNCTION()
	void AllPlayerLoginToGameStart();

	UFUNCTION()
	void HandlePlayerCharacterClass(APlayerController* Player, TSubclassOf<APawn> CharacterClass);

private:
	void SpawnPlayerCharacters();

private:
	// 유저 접속을 확인하는 타이머
	FTimerHandle PlayerLoginTimerHandle;

	TMap<APlayerController*, TSubclassOf<APawn>> CharacterClassMap;
};
