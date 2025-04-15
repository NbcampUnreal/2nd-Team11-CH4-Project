// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterButtonUserWidget.generated.h"

class UButton;

UCLASS()
class SSBPROJECT_API UCharacterButtonUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION()
	void PlayerCharacterSetting();

	UButton* GetCharacterButton() const;

	void SetSelectedCharacterClass(TSubclassOf<APawn> NewSelectedCharacterClass);

protected:
	virtual void NativeConstruct() override;

protected:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> CharacterButton;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Character")
	TSubclassOf<APawn> SelectedCharacterClass;
};
