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

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetPlayerIndex();
	void SetPlayerIndex(int32 NewPlayerIndex);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetStock();
	UFUNCTION(BlueprintCallable)
	void SetStock(int32 NewStock);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetSuperNum();
	UFUNCTION(BlueprintCallable)
	void SetSuperNum(int32 NewSuper);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int32 GetHPPercent();
	UFUNCTION(BlueprintCallable)
	void SetHPPercent(int32 NewHPPercent);

protected:
	// 플레이어 정보
	UPROPERTY(Replicated, VisibleAnywhere, Category = "Player")
	int32 PlayerIndex; // 접속 순서 (0번부터 시작)
	
	// 캐릭터 정보
	UPROPERTY(Replicated, VisibleAnywhere, Category = "Character")
	EPlayerStates States;

	UPROPERTY(Replicated, VisibleAnywhere, Category = "Character")
	int32 Stock;

	UPROPERTY(Replicated, VisibleAnywhere, Category = "Character")
	int32 SuperNum;

	UPROPERTY(Replicated, VisibleAnywhere, Category = "Character")
	int32 HPPercent;
};
