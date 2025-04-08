#include "TitleWidgetController.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void ATitleWidgetController::BeginPlay()
{
	Super::BeginPlay();

	if (true == ::IsValid(UIWidgetClass))
	{
		UIWidgetInstance = CreateWidget<UUserWidget>(this, UIWidgetClass);
		// CreateWidget()이 호출될 때 UIWidgetInstance->NativeOnInitialize() 함수가 호출됨.
		if (true == ::IsValid(UIWidgetInstance))
		{
			UIWidgetInstance->AddToViewport();
			// AddToViewport()가 호출 될 때 UIWidgetInstance->NativeConstruct() 함수가 호출됨.

			FInputModeUIOnly Mode;
			Mode.SetWidgetToFocus(UIWidgetInstance->GetCachedWidget());
			SetInputMode(Mode);

			bShowMouseCursor = true;
		}
	}
}

void ATitleWidgetController::SetTitleCameraView()
{
	TArray<AActor*> FoundCameras;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), FoundCameras);

	for (AActor* Actor : FoundCameras)
	{
		if (Actor->GetName().Contains(TEXT("TitleCamera"))) // 카메라 이름 기준
		{
			SetViewTargetWithBlend(Actor, 1.0f);
			break;
		}
	}
}