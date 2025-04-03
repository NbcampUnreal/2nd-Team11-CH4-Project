#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MainMenuUserWidget.generated.h"

UCLASS()
class SSBPROJECT_API UMainMenuUserWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UMainMenuUserWidget(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());

protected:

	virtual void NativeConstruct();

	UFUNCTION()
	void OnExitButtonClicked();

private:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> ExitButton;
};
