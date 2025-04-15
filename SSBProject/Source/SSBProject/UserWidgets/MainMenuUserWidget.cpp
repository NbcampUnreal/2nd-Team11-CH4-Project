#include "MainMenuUserWidget.h"
#include "ModeCardUserWidget.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CharacterSelectUserWidget.h"
#include "MainMenuPlayerController.h"

UMainMenuUserWidget::UMainMenuUserWidget(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
{
}

void UMainMenuUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (SingleCardButton)
    {
        SingleCardButton->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OnSingleCardClicked);
    }
    {
    if (MultiplayerCardButton)
        MultiplayerCardButton->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OnMultiplayerCardClicked);
    }
    {
    if (CoopCardButton)
        CoopCardButton->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OnCoopCardClicked);
    }
    if (ExitButton)
    {
        ExitButton->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OnExitButtonClicked);
    }

    CreateModeCard(FText::FromString(TEXT("SINGLE")), FText::FromString(TEXT("1인 플레이")), SingleIcon, EGameModes::Scenario);
    //CreateModeCard(FText::FromString(TEXT("CO-OP")), FText::FromString(TEXT("2인 협력")), CoopIcon, EGameModes::PVE);
    CreateModeCard(FText::FromString(TEXT("VERSUS")), FText::FromString(TEXT("1vs1 또는 2vs2")), VersusIcon, EGameModes::PVP);
    CreateModeCard(FText::FromString(TEXT("OPTIONS")), FText::FromString(TEXT("설정 메뉴")), OptionsIcon, EGameModes::None);

}

void UMainMenuUserWidget::CreateModeCard(FText Title, FText Desc, UTexture2D* Icon, EGameModes ModeType)
{
    if (CardWidgetClass && CardBox)
    {
        UModeCardUserWidget* Card = CreateWidget<UModeCardUserWidget>(GetWorld(), CardWidgetClass);
        if (Card)
        {
            Card->SetCardData(Icon, Title, Desc, ModeType);
            Card->OnCardClicked.AddDynamic(this, &UMainMenuUserWidget::HandleCardClick);
            CardBox->AddChild(Card);
        }
    }
}

void UMainMenuUserWidget::HandleCardClick(EGameModes ModeType)
{
    if (ModeType != EGameModes::None)
    {
        OpenCharacterSelect();
    }
}

UUserWidget* UMainMenuUserWidget::OpenCharacterSelect()
{
    UUserWidget* CharacterUI = nullptr;
    if (UWorld* World = GetWorld())
    {
        CharacterUI = CreateWidget<UUserWidget>(
            World,
            LoadClass<UUserWidget>(nullptr, TEXT("/Game/Blueprints/UserWidgets/WBP_CharacterUserWidget.WBP_CharacterUserWidget_C"))
        );

        if (CharacterUI)
        {
            CharacterUI->AddToViewport();

            AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
            if (PlayerController)
            {
                PlayerController->SetCharacterSelectUserWidgetInstance(CharacterUI);
            }
            
            RemoveFromParent();
        }
    }

    return CharacterUI;
}

void UMainMenuUserWidget::OnExitButtonClicked()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
}
void UMainMenuUserWidget::OnSingleCardClicked()
{
    UCharacterSelectUserWidget* CharacterSelect = Cast<UCharacterSelectUserWidget>(OpenCharacterSelect());

    if (CharacterSelect)
    {
        TArray<int32> TargetPlayerCount;
        TargetPlayerCount.Add(1);

        AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
        if (PlayerController)
        {
            PlayerController->ServerSetGameCharacterConfiguration(TargetPlayerCount, 1);
        }
    }
}

void UMainMenuUserWidget::OnMultiplayerCardClicked()
{
    UCharacterSelectUserWidget* CharacterSelect = Cast<UCharacterSelectUserWidget>(OpenCharacterSelect());

    if (CharacterSelect)
    {
        TArray<int32> TargetPlayerCount;
        TargetPlayerCount.Add(2);
        TargetPlayerCount.Add(4);
        
        AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
        if (PlayerController)
        {
            PlayerController->ServerSetGameCharacterConfiguration(TargetPlayerCount, 0);
        }
    }
}

void UMainMenuUserWidget::OnCoopCardClicked()
{
    UCharacterSelectUserWidget* CharacterSelect = Cast<UCharacterSelectUserWidget>(OpenCharacterSelect());

    if (CharacterSelect)
    {
        TArray<int32> TargetPlayerCount;
        TargetPlayerCount.Add(2);
        
        AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
        if (PlayerController)
        {
            PlayerController->ServerSetGameCharacterConfiguration(TargetPlayerCount, 2);
        }
    }
}
