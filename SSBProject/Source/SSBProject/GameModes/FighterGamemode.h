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

	virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

	virtual APawn* SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot) override;

protected:
	virtual void BeginPlay() override;

	virtual void PostLogin(APlayerController* NewPlayer) override;

public:
	UFUNCTION()
	void AllPlayerLoginToGameStart();

private:
	// ���� ������ Ȯ���ϴ� Ÿ�̸�
	FTimerHandle PlayerLoginTimerHandle;
};
