#include "MapUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MainMenuPlayerController.h"

void UMapUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (DollHouseMapButton)
    {
        DollHouseMapButton->OnClicked.AddDynamic(this, &UMapUserWidget::SelectDollHouseMap);
    }
    if (WildernessMapButton)
    {
        WildernessMapButton->OnClicked.AddDynamic(this, &UMapUserWidget::SelectWildernessMap);
    }
}

void UMapUserWidget::SelectDollHouseMap()
{
    AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
    if (PlayerController)
    {
        PlayerController->ServerMapTravelCall("/Game/Maps/L_DollHouse");
    }
}

void UMapUserWidget::SelectWildernessMap()
{
    AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
    if (PlayerController)
    {
        PlayerController->ServerMapTravelCall("/Game/Maps/L_Wilderness");
    }
}

void UMapUserWidget::Select111Map()
{
}

void UMapUserWidget::Select22Map()
{
}
