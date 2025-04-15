// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SSBPROJECT_API AMainMenuPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMainMenuPlayerController();

	virtual void BeginPlay() override;

public:
	UFUNCTION(Server, Reliable)
	void InitGameValue(int32 NewTotalCharacterCount, int32 NewTotalPlayerCount, int32 NewInitialStock, const TArray<TSubclassOf<APawn>>& NewAICharacterClassArray);

	UFUNCTION(Server, Reliable)
	void SetSelectCharacter(TSubclassOf<APawn> SelectedClass);

	UFUNCTION(Server, Reliable)
	void ServerAddSelectedPlayers(int32 PlayerID);

	UFUNCTION(Server, Reliable)
	void ServerSetGameCharacterConfiguration(const TArray<int32>& NewTargetPlayerCount, int32 NewAICharacterCount);


	UFUNCTION(Server, Reliable)
	void ServerUpdateUI(const TArray<int32>& TargetPlayerCount, const TArray<int32>& SelectedPlayers);
	UFUNCTION(NetMulticast, Reliable)
	void MulticastUpdateUI(const TArray<int32>& TargetPlayerCount, const TArray<int32>& SelectedPlayers);

	UFUNCTION(Server, Reliable)
	void ServerMapTravelCall(const FString& MapName);

	UFUNCTION()
	void SetCharacterSelectUserWidgetInstance(UUserWidget* NewCharacterSelectUserWidgetInstance);

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	TObjectPtr<UUserWidget> MainMenuWidgetInstance;

private:
	UPROPERTY(VisibleAnywhere, Category = "UI")
	TObjectPtr<UUserWidget> CharacterSelectUserWidgetInstance;
};
