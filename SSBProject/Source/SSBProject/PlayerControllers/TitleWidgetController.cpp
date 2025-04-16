#include "TitleWidgetController.h"
#include "Blueprint/UserWidget.h"
#include "Camera/CameraActor.h"
#include "Kismet/GameplayStatics.h"

void ATitleWidgetController::BeginPlay()
{
	Super::BeginPlay();
	
	if (IsLocalController())
	{
		SetTitleCameraView();
	}

	if (IsLocalController() && true == IsValid(UIWidgetClass))
	{
		UIWidgetInstance = CreateWidget<UUserWidget>(this, UIWidgetClass);
		// CreateWidget()�� ȣ��� �� UIWidgetInstance->NativeOnInitialize() �Լ��� ȣ���.
		if (UIWidgetInstance)
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

void ATitleWidgetController::SetTitleCameraView()
{
	TArray<AActor*> FoundCameras;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACameraActor::StaticClass(), FoundCameras);

	for (AActor* Actor : FoundCameras)
	{
		if (Actor->ActorHasTag("Camera")) // ī�޶� �̸� ����
		{
			SetViewTargetWithBlend(Actor, 0.0f);
			break;
		}
	}
}