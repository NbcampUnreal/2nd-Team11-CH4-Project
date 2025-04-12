#include "MainMenuUserWidget.h"
#include "ModeCardUserWidget.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

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

void UMainMenuUserWidget::OpenCharacterSelect()
{
    if (UWorld* World = GetWorld())
    {
        UUserWidget* CharacterUI = CreateWidget<UUserWidget>(
            World,
            LoadClass<UUserWidget>(nullptr, TEXT("/Game/Blueprints/UserWidgets/BP_CharacterUserWidget.BP_CharacterUserWidget_C"))
        );

        if (CharacterUI)
        {
            CharacterUI->AddToViewport();
            RemoveFromParent();
        }
    }
}

void UMainMenuUserWidget::OnExitButtonClicked()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
}
void UMainMenuUserWidget::OnSingleCardClicked()
{
    OpenCharacterSelect();
}

void UMainMenuUserWidget::OnMultiplayerCardClicked()
{
    OpenCharacterSelect();
}

void UMainMenuUserWidget::OnCoopCardClicked()
{
    OpenCharacterSelect();
}
