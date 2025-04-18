#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MapUserWidget.generated.h"

class UButton;
class UCircularThrobber;

UCLASS()
class SSBPROJECT_API UMapUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void SelectDollHouseMap();

    UFUNCTION()
    void SelectWildernessMap();

    UFUNCTION()
    void SelectBattlePlaceMap();

    UFUNCTION()
    void SelectOceanMap();

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* DollHouseMapButton;

    UPROPERTY(meta = (BindWidget))
    UButton* WildernessMapButton;

    UPROPERTY(meta = (BindWidget))
    UButton* BattlePlaceMapButton;

    UPROPERTY(meta = (BindWidget))
    UButton* OceanMapButton;

    UPROPERTY(meta = (BindWidget))
    UCircularThrobber* Loading;
};