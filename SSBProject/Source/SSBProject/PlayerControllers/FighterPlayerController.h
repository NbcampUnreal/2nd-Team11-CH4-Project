// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FighterPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class SSBPROJECT_API AFighterPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AFighterPlayerController();

	virtual void BeginPlay() override;

public:
	UFUNCTION(Server, Reliable)
	void Server_SetSelectedCharacter(TSubclassOf<APawn> InClass);

public:
	void AddMapping();

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputMappingContext> IMC;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> LeftRightAction;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Input")
	TObjectPtr<UInputAction> UpDownAction;
};
