// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "MainMenuGameState.generated.h"



UCLASS()
class SSBPROJECT_API AMainMenuGameState : public AGameState
{
	GENERATED_BODY()
	
public:
	void AddSelectedPlayers(int32 PlayerID);
	void RemoveSelectedPlayers(int32 PlayerID);

	const TArray<int32>& GetSelectedPlayers();
	
private:
	// ĳ���͸� ������ �÷��̾�
	TArray<int32> SelectedPlayers;
	
};
