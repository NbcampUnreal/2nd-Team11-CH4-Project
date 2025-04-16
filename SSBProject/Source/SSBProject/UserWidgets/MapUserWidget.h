#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MapUserWidget.generated.h"

class UButton;

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
    void Select111Map();

    UFUNCTION()
    void Select22Map();

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* DollHouseMapButton;

    UPROPERTY(meta = (BindWidget))
    UButton* WildernessMapButton;
};