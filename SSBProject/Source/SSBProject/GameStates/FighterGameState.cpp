// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterGameState.h"
#include "Net/UnrealNetwork.h"

AFighterGameState::AFighterGameState()
{
	TotalCharacterCount = 0;
	PlayerJoinCount = 0;
}

void AFighterGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFighterGameState, TotalCharacterCount);
	DOREPLIFETIME(AFighterGameState, TotalPlayerCount);
	DOREPLIFETIME(AFighterGameState, PlayerJoinCount);
}

int32 AFighterGameState::GetTotalCharacterCount()
{
	return TotalCharacterCount;
}

void AFighterGameState::SetTotalCharacterCount(int32 NewTotalCharacterCount)
{
	TotalCharacterCount = NewTotalCharacterCount;
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
