#include "CharacterUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UCharacterUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (CharacterButton)
    {
        CharacterButton->OnClicked.AddDynamic(this, &UCharacterUserWidget::SelectCharacter);
    }
}

void UCharacterUserWidget::SelectCharacter()
{
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