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
}

void UMainMenuUserWidget::OnExitButtonClicked()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
}