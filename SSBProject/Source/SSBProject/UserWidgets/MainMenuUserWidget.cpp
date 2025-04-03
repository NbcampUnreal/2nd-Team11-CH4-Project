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
	Super::NativeConstruct(); // �θ� Ŭ������ NativeConstruct ȣ��

	if (ExitButton) // ExitButton�� nullptr���� Ȯ��
	{
		ExitButton->OnClicked.AddDynamic(this, &UMainMenuUserWidget::OnExitButtonClicked);
	}
}

void UMainMenuUserWidget::OnExitButtonClicked()
{
	UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, false);
}