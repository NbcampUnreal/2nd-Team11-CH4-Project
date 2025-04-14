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
	GetWorldTimerManager().SetTimer(TESTTimerHandle, this, &AMainMenuPlayerController::TESTFUNC, 1.f, false);

	if (IsLocalController() && MainMenuWidgetClass)
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

void AMainMenuPlayerController::TESTFUNC()
{
	if (TESTSelectedCharacterClass1)
	{
		SetSelectCharacter_Implementation(TESTSelectedCharacterClass1);
		TESTSelectedCharacterClass1 = nullptr;
	}
	else
	{
		SetSelectCharacter_Implementation(TESTSelectedCharacterClass2);
	}
}

void AMainMenuPlayerController::SetSelectCharacter_Implementation(TSubclassOf<APawn> SelectedClass)
{
	USSBGameInstance* CurInstnace = GetGameInstance<USSBGameInstance>();
	if (CurInstnace && PlayerState)
	{
		FString CurPlayerName = PlayerState->GetPlayerName();
		CurInstnace->SetSelectedCharacterClassMap(CurPlayerName, SelectedClass);
	}
}