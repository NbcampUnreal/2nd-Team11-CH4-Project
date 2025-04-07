// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "EnumList.h"
#include "FighterPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class SSBPROJECT_API AFighterPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AFighterPlayerState();
	
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	int32 GetPlayerIndex();
	void SetPlayerIndex(int32 NewPlayerIndex);

protected:
	// 플레이어 정보
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Player")
	int32 PlayerIndex; // 접속 순서 (0번부터 시작)
	
	// 캐릭터 정보
	UPROPERTY(Replicated, BlueprintReadOnly, Category = "Character")
	EPlayerStates States;
};
