// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuGameState.h"

void AMainMenuGameState::AddSelectedPlayers(int32 PlayerID)
{
	SelectedPlayers.Add(PlayerID);
}

void AMainMenuGameState::RemoveSelectedPlayers(int32 PlayerID)
{
	SelectedPlayers.Remove(PlayerID);
}

const TArray<int32>& AMainMenuGameState::GetSelectedPlayers()
{
	return SelectedPlayers;
}
