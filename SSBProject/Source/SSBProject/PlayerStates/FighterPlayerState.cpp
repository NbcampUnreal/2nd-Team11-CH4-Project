// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterPlayerState.h"
#include "Net/UnrealNetwork.h"

AFighterPlayerState::AFighterPlayerState()
{
	// 플레이어
	PlayerIndex = 0;

	// 캐릭터
	States = EPlayerStates::Idle;
	Stock = 0;
}

void AFighterPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFighterPlayerState, PlayerIndex);
	DOREPLIFETIME(AFighterPlayerState, States);
	DOREPLIFETIME(AFighterPlayerState, Stock);
	DOREPLIFETIME(AFighterPlayerState, SuperNum);
	DOREPLIFETIME(AFighterPlayerState, HPPercent);

}

int32 AFighterPlayerState::GetPlayerIndex()
{
	return PlayerIndex;
}

void AFighterPlayerState::SetPlayerIndex(int32 NewPlayerIndex)
{
	PlayerIndex = NewPlayerIndex;
}

int32 AFighterPlayerState::GetStock()
{
	return Stock;
}

void AFighterPlayerState::SetStock(int32 NewStock)
{
	Stock = NewStock;
}

int32 AFighterPlayerState::GetSuperNum()
{
	return SuperNum;
}

void AFighterPlayerState::SetSuperNum(int32 NewSuper)
{
	SuperNum = NewSuper;
}

int32 AFighterPlayerState::GetHPPercent()
{
	return HPPercent;
}

void AFighterPlayerState::SetHPPercent(int32 NewHPPercent)
{
	HPPercent = NewHPPercent;
}
