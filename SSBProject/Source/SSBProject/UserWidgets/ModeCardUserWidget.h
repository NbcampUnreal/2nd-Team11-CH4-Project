#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnumList.h"
#include "ModeCardUserWidget.generated.h"

class UImage;
class UTextBlock;
class UButton;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnModeCardClicked, EGameModes, Mode);

UCLASS()
class SSBPROJECT_API UModeCardUserWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    void SetCardData(UTexture2D* InIcon, FText InTitle, FText InDesc, EGameModes InMode);

    UPROPERTY(BlueprintAssignable, Category = "Event")
    FOnModeCardClicked OnCardClicked;

protected:
    virtual void NativeConstruct() override;

    UFUNCTION()
    void HandleClick();

    EGameModes ModeType;

    UPROPERTY(meta = (BindWidget)) UImage* IconImage;
    UPROPERTY(meta = (BindWidget)) UTextBlock* TitleText;
    UPROPERTY(meta = (BindWidget)) UTextBlock* DescText;
    UPROPERTY(meta = (BindWidget)) UButton* ClickButton;
};
