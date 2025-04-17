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
    if (BattlePlaceMapButton)
    {
        BattlePlaceMapButton->OnClicked.AddDynamic(this, &UMapUserWidget::SelectBattlePlaceMap);
    }
    if (OceanMapButton)
    {
        OceanMapButton->OnClicked.AddDynamic(this, &UMapUserWidget::SelectOceanMap);
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

void UMapUserWidget::SelectBattlePlaceMap()
{
    AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
    if (PlayerController)
    {
        PlayerController->ServerMapTravelCall("/Game/Maps/L_BattlePlace");
    }
}

void UMapUserWidget::SelectOceanMap()
{
    AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
    if (PlayerController)
    {
        PlayerController->ServerMapTravelCall("/Game/Maps/L_Ocean");
    }
}
