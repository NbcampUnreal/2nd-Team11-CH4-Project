// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterPlayerState.h"
#include "Net/UnrealNetwork.h"

AFighterPlayerState::AFighterPlayerState()
{
	PlayerIndex = 1;
}

void AFighterPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(AFighterPlayerState, PlayerIndex);

}

int32 AFighterPlayerState::GetPlayerIndex()
{
	return PlayerIndex;
}

void AFighterPlayerState::SetPlayerIndex(int32 NewPlayerIndex)
{
	PlayerIndex = NewPlayerIndex;
}
