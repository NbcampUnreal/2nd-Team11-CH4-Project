// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterGameState.h"
#include "Net/UnrealNetwork.h"

AFighterGameState::AFighterGameState()
{
	TotalPlayerCount = 0;
	PlayerJoinCount = 0;
}

void AFighterGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFighterGameState, TotalPlayerCount);
}

int32 AFighterGameState::GetTotalPlayerCount()
{
	return TotalPlayerCount;
}

void AFighterGameState::SetTotalPlayerCount(int32 NewTotalPlayerCount)
{
	TotalPlayerCount = NewTotalPlayerCount;
}

int32 AFighterGameState::GetPlayerJoinCount()
{
	return PlayerJoinCount;
}

void AFighterGameState::SetPlayerJoinCount(int32 NewPlayerJoinCount)
{
	PlayerJoinCount = NewPlayerJoinCount;
}
