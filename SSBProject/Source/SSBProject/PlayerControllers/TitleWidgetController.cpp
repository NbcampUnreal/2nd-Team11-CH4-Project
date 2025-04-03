#include "TitleWidgetController.h"
#include "Blueprint/UserWidget.h"

void ATitleWidgetController::BeginPlay()
{
	Super::BeginPlay();

	if (true == ::IsValid(UIWidgetClass))
	{
		UIWidgetInstance = CreateWidget<UUserWidget>(this, UIWidgetClass);
		// CreateWidget()�� ȣ��� �� UIWidgetInstance->NativeOnInitialize() �Լ��� ȣ���.
		if (true == ::IsValid(UIWidgetInstance))
		{
			UIWidgetInstance->AddToViewport();
			// AddToViewport()�� ȣ�� �� �� UIWidgetInstance->NativeConstruct() �Լ��� ȣ���.

			FInputModeUIOnly Mode;
			Mode.SetWidgetToFocus(UIWidgetInstance->GetCachedWidget());
			SetInputMode(Mode);

			bShowMouseCursor = true;
		}
	}
}

