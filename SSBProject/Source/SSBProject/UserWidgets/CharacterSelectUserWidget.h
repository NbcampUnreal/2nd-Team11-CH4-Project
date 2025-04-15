#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CharacterSelectUserWidget.generated.h"

class UHorizontalBox;
class UButton;
class UCharacterButtonUserWidget;

UCLASS()
class SSBPROJECT_API UCharacterSelectUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
    UFUNCTION()
    void SelectCharacter();

    UFUNCTION()
    void ChangeRandomCharacter();

    UFUNCTION()
    void SetupGameStart();

    void UpdateUI(const TArray<int32>& TargetPlayerCount, const TArray<int32>& SelectedPlayers);

protected:
    virtual void NativeConstruct() override;

protected:
    // 시작 버튼
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
    TObjectPtr<UButton> StartButton;

    // 캐릭터 선택
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
    TObjectPtr<UHorizontalBox> CharacterHorizontalBox;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
    TObjectPtr<UCharacterButtonUserWidget> FistFighterButton;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
    TObjectPtr<UCharacterButtonUserWidget> GunFighterButton;
    
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
    TObjectPtr<UCharacterButtonUserWidget> HatsButton;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
    TObjectPtr<UCharacterButtonUserWidget> MageButton;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
    TObjectPtr<UCharacterButtonUserWidget> SwordFighterButton;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (BindWidget))
    TObjectPtr<UCharacterButtonUserWidget> RandomButton;
};