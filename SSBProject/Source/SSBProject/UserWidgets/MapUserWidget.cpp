#include "MapUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"

void UMapUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (MapButton1)
    {
        MapButton1->OnClicked.AddDynamic(this, &UMapUserWidget::SelectMap);
    }
    if (MapButton2)
    {
        MapButton2->OnClicked.AddDynamic(this, &UMapUserWidget::SelectMap);
    }
}

void UMapUserWidget::SelectMap()
{
    UGameplayStatics::OpenLevel(this, FName("BattlePlace"));
}