#include "MainMenuUserWidget.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/GameplayStatics.h"

UMainMenuUserWidget::UMainMenuUserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
}


void UMainMenuUserWidget::NativeConstruct()
{
	Super::NativeConstruct(); // 부모 클래스의 NativeConstruct 호출

	if (ExitButton) // ExitButton이 nullptr인지 확인
	{
		ExitButton->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OnExitButtonClicked);
	}
    if (SingleButton)
    {
        SingleButton->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OpenCharacterSelect);
    }
    if (MultiplayerButton)
    {
        MultiplayerButton->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OpenCharacterSelect);
    }
    if (CoopButton)
    {
        CoopButton->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OpenCharacterSelect);
    }
}

void UMainMenuUserWidget::OnExitButtonClicked()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
}

void UMainMenuUserWidget::OpenCharacterSelect()
{
    if (UWorld* World = GetWorld())
    {
        UUserWidget* CharacterUserWidget = CreateWidget<UUserWidget>(World, LoadClass<UUserWidget>(nullptr, TEXT("/Game/Blueprints/UserWidgets/BP_CharacterUserWidget.BP_CharacterUserWidget_C")));

        if (CharacterUserWidget)
        {
            CharacterUserWidget->AddToViewport();
            RemoveFromParent();
        }
    }
}