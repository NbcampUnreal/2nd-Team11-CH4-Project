#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TitleWidgetController.generated.h"

UCLASS()
class SSBPROJECT_API ATitleWidgetController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = APlayerController, Meta = (AllowPrivateAccess))
	TSubclassOf<UUserWidget> UIWidgetClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = APlayerController, Meta = (AllowPrivateAccess))
	TObjectPtr<UUserWidget> UIWidgetInstance;

	void SetTitleCameraView();
};
