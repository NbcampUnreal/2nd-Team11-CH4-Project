#include "MapUserWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "MainMenuPlayerController.h"
#include "Components/CircularThrobber.h"

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
        Loading->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
    }
}

void UMapUserWidget::SelectWildernessMap()
{
    AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
    if (PlayerController)
    {
        PlayerController->ServerMapTravelCall("/Game/Maps/L_Wilderness");
        Loading->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
    }
}

void UMapUserWidget::SelectBattlePlaceMap()
{
    AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
    if (PlayerController)
    {
        PlayerController->ServerMapTravelCall("/Game/Maps/L_BattlePlace");
        Loading->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
    }
}

void UMapUserWidget::SelectOceanMap()
{
    AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
    if (PlayerController)
    {
        PlayerController->ServerMapTravelCall("/Game/Maps/L_Ocean");
        Loading->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
    }
}
