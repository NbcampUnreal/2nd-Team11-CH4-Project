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

    // ��ư ���ε�
    UPROPERTY(meta = (BindWidget))
    UButton* SingleCardButton;

    UPROPERTY(meta = (BindWidget))
    UButton* MultiplayerCardButton;

    UPROPERTY(meta = (BindWidget))
    UButton* CoopCardButton;

    // Ŭ�� �Լ���
    UFUNCTION()
    void OnSingleCardClicked();

    UFUNCTION()
    void OnMultiplayerCardClicked();

    UFUNCTION()
    void OnCoopCardClicked();

    // ȭ�� ��ȯ��
    UUserWidget* OpenCharacterSelect();

    void CreateModeCard(FText Title, FText Desc, UTexture2D* Icon, EGameModes ModeType);


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
