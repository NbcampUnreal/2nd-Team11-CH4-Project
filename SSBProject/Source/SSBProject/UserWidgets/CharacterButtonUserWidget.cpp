// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterButtonUserWidget.h"
#include "Components/Button.h"
#include "MainMenuPlayerController.h"

void UCharacterButtonUserWidget::PlayerCharacterSetting()
{
    AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
    if (PlayerController)
    {
        PlayerController->SetSelectCharacter(SelectedCharacterClass);
    }
}

UButton* UCharacterButtonUserWidget::GetCharacterButton() const
{
    return CharacterButton;
}

void UCharacterButtonUserWidget::SetSelectedCharacterClass(TSubclassOf<APawn> NewSelectedCharacterClass)
{
    SelectedCharacterClass = NewSelectedCharacterClass;
}

void UCharacterButtonUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

    if (CharacterButton)
    {
        CharacterButton->OnClicked.AddDynamic(this, &UCharacterButtonUserWidget::PlayerCharacterSetting);
    }
}
