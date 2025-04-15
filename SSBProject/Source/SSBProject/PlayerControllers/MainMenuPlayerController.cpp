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

// ������� �� ĳ���� ��, �÷��̾� ��, ��� ����, ������ AI Ŭ���� ����
void AMainMenuPlayerController::InitGameValue_Implementation(int32 NewTotalCharacterCount, int32 NewTotalPlayerCount, int32 NewInitialStock, const TArray<TSubclassOf<APawn>>& NewAICharacterClassArray)
{
	USSBGameInstance* CurInstnace = GetGameInstance<USSBGameInstance>();
	if (CurInstnace)
	{
		CurInstnace->SetTotalCharacterCount(NewTotalCharacterCount);
		CurInstnace->SetTotalPlayerCount(NewTotalPlayerCount);
		CurInstnace->SetInitialStock(NewInitialStock);
		CurInstnace->SetSelectedAICharacterClassArray(NewAICharacterClassArray);
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