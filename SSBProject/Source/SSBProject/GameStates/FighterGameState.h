// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "FighterGameState.generated.h"

/**
 * 
 */
UCLASS()
class SSBPROJECT_API AFighterGameState : public AGameState
{
	GENERATED_BODY()

public:
	AFighterGameState();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	int32 GetTotalPlayerCount();
	void SetTotalPlayerCount(int32 NewTotalPlayerCount);

	int32 GetPlayerJoinCount();
	void SetPlayerJoinCount(int32 NewPlayerJoinCount);
	
protected:
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	int32 TotalPlayerCount;	// ���� �̵��� �Ǿ���� �� �÷��̾��� ��
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	int32 PlayerJoinCount;	// ���� �̵��� �� �÷��̾��� ���� ī��Ʈ
};
