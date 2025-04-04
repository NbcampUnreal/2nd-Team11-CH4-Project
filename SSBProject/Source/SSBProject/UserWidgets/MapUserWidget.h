#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MapUserWidget.generated.h"

UCLASS()
class SSBPROJECT_API UMapUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    class UButton* MapButton1;

    UPROPERTY(meta = (BindWidget))
    class UButton* MapButton2;

    UFUNCTION()
    void SelectMap();
};