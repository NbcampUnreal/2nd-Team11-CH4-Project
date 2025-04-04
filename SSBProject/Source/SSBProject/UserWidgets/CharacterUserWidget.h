#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterUserWidget.generated.h"


UCLASS()
class SSBPROJECT_API UCharacterUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
protected:
    virtual void NativeConstruct() override;

    UPROPERTY(meta = (BindWidget))
    class UButton* CharacterButton;

    UFUNCTION()
    void SelectCharacter();
};