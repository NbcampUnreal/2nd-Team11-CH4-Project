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
	void SetSelectCharacter(TSubclassOf<APawn> SelectedClass);

	//TEST
	void TESTFUNC();

	UPROPERTY(EditAnywhere)
	TSubclassOf<APawn> TESTSelectedCharacterClass1;
	UPROPERTY(EditAnywhere)
	TSubclassOf<APawn> TESTSelectedCharacterClass2;

	FTimerHandle TESTTimerHandle;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "UI")
	TSubclassOf<UUserWidget> MainMenuWidgetClass;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "UI")
	TObjectPtr<UUserWidget> MainMenuWidgetInstance;

};
