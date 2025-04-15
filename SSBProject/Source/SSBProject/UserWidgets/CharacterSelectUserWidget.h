#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterSelectUserWidget.generated.h"

class UButton;
class UCharacterButtonUserWidget;

UCLASS()
class SSBPROJECT_API UCharacterSelectUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION()
    void SelectCharacter();

protected:
    virtual void NativeConstruct() override;

protected:
    UPROPERTY(meta = (BindWidget))
    UButton* CharacterButton;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
    TObjectPtr<UCharacterButtonUserWidget> MageButton;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
    TObjectPtr<UCharacterButtonUserWidget> SwordFighterButton;
};