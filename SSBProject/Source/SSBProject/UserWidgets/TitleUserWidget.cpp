#include "TitleUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "TitleWidgetController.h"
#include "Components/CircularThrobber.h"

UTitleUserWidget::UTitleUserWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bIsFocusable = true; // UI가 키 입력을 받을 수 있도록 설정
}

void UTitleUserWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// 키보드 입력을 받을 수 있도록 포커스 설정
	SetKeyboardFocus();

	// UI 전용 입력 모드 설정 (마우스 커서도 표시)
	FInputModeUIOnly InputMode;
	InputMode.SetWidgetToFocus(TakeWidget());
	GetOwningPlayer()->SetInputMode(InputMode);
	GetOwningPlayer()->bShowMouseCursor = true;
}

FReply UTitleUserWidget::NativeOnKeyDown(const FGeometry& InGeometry, const FKeyEvent& InKeyEvent)
{
	// 아무 키나 누르면 다음 레벨로 이동
	//UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainMenuMap"));

	ATitleWidgetController* PlayerController = GetOwningPlayer<ATitleWidgetController>();
	if (PlayerController)
	{
		PlayerController->ServerRequestMainMenuTravel(PlayerController);
		Loading->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	}

	return FReply::Handled();
}