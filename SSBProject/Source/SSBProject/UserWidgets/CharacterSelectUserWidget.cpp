#include "CharacterSelectUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MainMenuPlayerController.h"
#include "SSBGameInstance.h"
#include "CharacterButtonUserWidget.h"

void UCharacterSelectUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (CharacterButton)
    {
        CharacterButton->OnClicked.AddDynamic(this, &UCharacterSelectUserWidget::SelectCharacter);
    }

    if (MageButton)
    {
        MageButton->GetCharacterButton()->OnClicked.AddDynamic(this, &UCharacterSelectUserWidget::SelectCharacter);
    }
    
    if (SwordFighterButton)
    {
        SwordFighterButton->GetCharacterButton()->OnClicked.AddDynamic(this, &UCharacterSelectUserWidget::SelectCharacter);
    }
}

void UCharacterSelectUserWidget::SelectCharacter()
{
    TArray<TSubclassOf<APawn>> NewAICharacterClassArray;
    USSBGameInstance* CurInstnace = GetGameInstance<USSBGameInstance>();

    if (CurInstnace)
    {
        const TArray<TSubclassOf<APawn>> CharacterClassArray = CurInstnace->GetCharacterClassArray();
        int32 RandomIndex = FMath::RandRange(0, CharacterClassArray.Num() - 1);
        NewAICharacterClassArray.Add(CharacterClassArray[RandomIndex]);
    }

    AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
    if (PlayerController)
    {
        PlayerController->InitGameValue(2, 1, 3, NewAICharacterClassArray);
    }

    if (UWorld* World = GetWorld())
    {
        UUserWidget* MapUserWidget = CreateWidget<UUserWidget>(World, LoadClass<UUserWidget>(nullptr, TEXT("/Game/Blueprints/UserWidgets/BP_MapUserWidget.BP_MapUserWidget_C")));
        if (MapUserWidget)
        {
            MapUserWidget->AddToViewport();
            RemoveFromParent();
        }
    }
}