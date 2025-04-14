// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuPlayerController.h"
#include "GameFramework/PlayerState.h"
#include "SSBGameInstance.h"
#include "Blueprint/UserWidget.h"

AMainMenuPlayerController::AMainMenuPlayerController()
{
	MainMenuWidgetClass = nullptr;
	MainMenuWidgetInstance = nullptr;
}

void AMainMenuPlayerController::BeginPlay()
{
	Super::BeginPlay();

	//TEST
	if (TESTSelectedCharacterClass1)
	{
		SetSelectCharacter_Implementation(TESTSelectedCharacterClass1);
		TESTSelectedCharacterClass1 = nullptr;
	}
	else
	{
		SetSelectCharacter_Implementation(TESTSelectedCharacterClass2);
	}

	if (MainMenuWidgetClass)
	{
		MainMenuWidgetInstance = CreateWidget<UUserWidget>(this, MainMenuWidgetClass);

		if (MainMenuWidgetInstance)
		{
			MainMenuWidgetInstance->AddToViewport();

			SetShowMouseCursor(true);
			SetInputMode(FInputModeUIOnly());
		}
	}
}

void AMainMenuPlayerController::SetSelectCharacter_Implementation(TSubclassOf<APawn> SelectedClass)
{
	USSBGameInstance* CurInstnace = GetGameInstance<USSBGameInstance>();
	if (CurInstnace)
	{
		FString CurPlayerName = PlayerState->GetPlayerName();
		CurInstnace->SetSelectedCharacterClassMap(CurPlayerName, SelectedClass);
	}
}

void AMainMenuPlayerController::ServerMapTravel_Implementation(const FString& MapName)
{
	if (GetWorld() && GetWorld()->GetAuthGameMode())
	{
		FString Command = FString::Printf(TEXT("%s?listen"), *MapName);
		GetWorld()->ServerTravel(Command);
	}
}