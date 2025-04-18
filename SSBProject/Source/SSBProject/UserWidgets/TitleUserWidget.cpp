#include "TitleUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TitleWidgetController.h"
#include "Components/CircularThrobber.h"

UTitleUserWidget::UTitleUserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bIsFocusable = true; // UI�� Ű �Է��� ���� �� �ֵ��� ����
}

void UTitleUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Ű���� �Է��� ���� �� �ֵ��� ��Ŀ�� ����
	SetKeyboardFocus();

	// UI ���� �Է� ��� ���� (���콺 Ŀ���� ǥ��)
	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(TakeWidget());
	GetOwningPlayer()->SetInputMode(InputMode);
	GetOwningPlayer()->bShowMouseCursor = true;
}

FReply UTitleUserWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	// �ƹ� Ű�� ������ ���� ������ �̵�
	//UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenuMap"));

	ATitleWidgetController* PlayerController = GetOwningPlayer<ATitleWidgetController>();
	if (PlayerController)
	{
		PlayerController->ServerRequestMainMenuTravel(PlayerController);
		Loading->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}

	return FReply::Handled();
}