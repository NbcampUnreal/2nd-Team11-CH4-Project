// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenuPlayerController.h"
#include "GameFramework/PlayerState.h"
#include "SSBGameInstance.h"
#include "Blueprint/UserWidget.h"
#include "MainMenuGameState.h"
#include "MainMenuGameMode.h"
#include "CharacterSelectUserWidget.h"

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

void AMainMenuPlayerController::ServerAddSelectedPlayers_Implementation(int32 PlayerID)
{
	if (GetWorld())
	{
		AMainMenuGameMode* MainMenuGameMode = GetWorld()->GetAuthGameMode<AMainMenuGameMode>();
		AMainMenuGameState* MainMenuGameState = GetWorld()->GetGameState<AMainMenuGameState>();
		if (MainMenuGameState)
		{
			MainMenuGameState->AddSelectedPlayers(PlayerID);
			
			MulticastUpdateUI(MainMenuGameMode->GetTargetPlayerCount(), MainMenuGameState->GetSelectedPlayers());
		}
	}
}

void AMainMenuPlayerController::ServerUpdateUI_Implementation(const TArray<int32>& TargetPlayerCount, const TArray<int32>& SelectedPlayers)
{
	UCharacterSelectUserWidget* CharacterSelectUserWidget = Cast<UCharacterSelectUserWidget>(CharacterSelectUserWidgetInstance);

	if (CharacterSelectUserWidget)
	{
		CharacterSelectUserWidget->UpdateUI(TargetPlayerCount, SelectedPlayers);
	}
}

void AMainMenuPlayerController::MulticastUpdateUI_Implementation(const TArray<int32>& TargetPlayerCount, const TArray<int32>& SelectedPlayers)
{
	UCharacterSelectUserWidget* CharacterSelectUserWidget = Cast<UCharacterSelectUserWidget>(CharacterSelectUserWidgetInstance);

	if (CharacterSelectUserWidget)
	{
		CharacterSelectUserWidget->UpdateUI(TargetPlayerCount, SelectedPlayers);
	}
}

void AMainMenuPlayerController::ServerSetGameCharacterConfiguration_Implementation(const TArray<int32>& NewTargetPlayerCount, int32 NewAICharacterCount)
{
	AMainMenuGameMode* MainMenuGameMode = GetWorld()->GetAuthGameMode<AMainMenuGameMode>();

	if (MainMenuGameMode)
	{
		MainMenuGameMode->SetGameCharacterConfiguration(NewTargetPlayerCount, NewAICharacterCount);
	}
}

void AMainMenuPlayerController::ServerMapTravelCall_Implementation(const FString& MapName)
{
	USSBGameInstance* SSBGameInstance = GetGameInstance<USSBGameInstance>();
	SSBGameInstance->ServerMapTravel(MapName);
}

void AMainMenuPlayerController::SetCharacterSelectUserWidgetInstance(UUserWidget* NewCharacterSelectUserWidgetInstance)
{
	CharacterSelectUserWidgetInstance = NewCharacterSelectUserWidgetInstance;
}

// 순서대로 총 캐릭터 수, 플레이어 수, 목숨 개수, 스폰될 AI 클래스 종류
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
	if (CurInstnace && PlayerState && SelectedClass)
	{
		FString CurPlayerName = PlayerState->GetPlayerName();
		CurInstnace->SetSelectedCharacterClassMap(CurPlayerName, SelectedClass);
	}
}