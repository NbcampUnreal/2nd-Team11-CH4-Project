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

	virtual void StartPlay() override;

	virtual FString InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal = TEXT("")) override;

	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

	virtual APawn* SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot) override;

protected:
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

public:
	UFUNCTION()
	void AllPlayerLoginToGameStart();

private:
	// 유저 접속을 확인하는 타이머
	FTimerHandle PlayerLoginTimerHandle;
};
