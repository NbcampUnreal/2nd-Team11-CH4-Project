#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "EnumList.h"
#include "MainMenuUserWidget.generated.h"

class UButton;
class UHorizontalBox;
class UTexture2D;
class UModeCardUserWidget;

UCLASS()
class SSBPROJECT_API UMainMenuUserWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UMainMenuUserWidget(const FObjectInitializer& ObjectInitializer);

protected:
    virtual void NativeConstruct() override;

    void CreateModeCard(FText Title, FText Desc, UTexture2D* Icon, EGameModes ModeType);
    void OpenCharacterSelect();

    UFUNCTION()
    void HandleCardClick(EGameModes ModeType);

    UFUNCTION()
    void OnExitButtonClicked();

    UPROPERTY(meta = (BindWidget)) UButton* ExitButton;
    UPROPERTY(meta = (BindWidget)) UHorizontalBox* CardBox;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI") TSubclassOf<UModeCardUserWidget> CardWidgetClass;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI") UTexture2D* SingleIcon;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI") UTexture2D* CoopIcon;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI") UTexture2D* VersusIcon;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UI") UTexture2D* OptionsIcon;
};
