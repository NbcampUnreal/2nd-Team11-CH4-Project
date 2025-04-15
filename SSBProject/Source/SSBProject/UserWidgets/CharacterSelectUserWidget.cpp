#include "CharacterSelectUserWidget.h"
#include "Components/Button.h"
#include "Components/HorizontalBox.h"
#include "Kismet/GameplayStatics.h"
#include "MainMenuPlayerController.h"
#include "SSBGameInstance.h"
#include "CharacterButtonUserWidget.h"
#include "MainMenuPlayerState.h"
#include "MainMenuGameState.h"
#include "MainMenuGameMode.h"

void UCharacterSelectUserWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (FistFighterButton)
    {
        UButton* Button = FistFighterButton->GetCharacterButton();
        if (Button)
        {
            Button->OnClicked.AddDynamic(this, &UCharacterSelectUserWidget::SelectCharacter);
        }
    }
    if (GunFighterButton)
    {
        UButton* Button = GunFighterButton->GetCharacterButton();
        if (Button)
        {
            Button->OnClicked.AddDynamic(this, &UCharacterSelectUserWidget::SelectCharacter);
        }
    }
    if (HatsButton)
    {
        UButton* Button = HatsButton->GetCharacterButton();
        if (Button)
        {
            Button->OnClicked.AddDynamic(this, &UCharacterSelectUserWidget::SelectCharacter);
        }
    }
    if (MageButton)
    {
        UButton* Button = MageButton->GetCharacterButton();
        if (Button)
        {
            Button->OnClicked.AddDynamic(this, &UCharacterSelectUserWidget::SelectCharacter);
        }
    }
    if (SwordFighterButton)
    {
        UButton* Button = SwordFighterButton->GetCharacterButton();
        if (Button)
        {
            Button->OnClicked.AddDynamic(this, &UCharacterSelectUserWidget::SelectCharacter);
        }
    }
    if (RandomButton)
    {
        UButton* Button = RandomButton->GetCharacterButton();
        if (Button)
        {
            ChangeRandomCharacter();
            Button->OnClicked.AddDynamic(this, &UCharacterSelectUserWidget::SelectCharacter);
            Button->OnClicked.AddDynamic(this, &UCharacterSelectUserWidget::ChangeRandomCharacter);
        }
    }

    if (StartButton)
    {
        StartButton->OnClicked.AddDynamic(this, &UCharacterSelectUserWidget::SetupGameStart);
    }
}

void UCharacterSelectUserWidget::SelectCharacter()
{
    if (CharacterHorizontalBox)
    {
        CharacterHorizontalBox->SetVisibility(ESlateVisibility::HitTestInvisible);
    }

    AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
    if (PlayerController)
    {
        PlayerController->ServerAddSelectedPlayers(PlayerController->PlayerState->GetPlayerId());
    }
}

void UCharacterSelectUserWidget::ChangeRandomCharacter()
{
    USSBGameInstance* CurInstnace = GetGameInstance<USSBGameInstance>();
    if (CurInstnace)
    {
        const TArray<TSubclassOf<APawn>> CharacterClassArray = CurInstnace->GetCharacterClassArray();
        int32 RandomIndex = FMath::RandRange(0, CharacterClassArray.Num() - 1);
        if (RandomButton)
        {
            RandomButton->SetSelectedCharacterClass(CharacterClassArray[RandomIndex]);
        }
    }
}

void UCharacterSelectUserWidget::SetupGameStart()
{
    // AI가 사용할 캐릭터 클래스
    TArray<TSubclassOf<APawn>> NewAICharacterClassArray;

    USSBGameInstance* CurInstnace = GetGameInstance<USSBGameInstance>();
    AMainMenuGameMode* MainMenuGameMode = GetWorld()->GetAuthGameMode<AMainMenuGameMode>();
    AMainMenuGameState* MainMenuGameState = GetWorld()->GetGameState<AMainMenuGameState>();

    if (CurInstnace && MainMenuGameMode && MainMenuGameState)
    {
        const TArray<TSubclassOf<APawn>> CharacterClassArray = CurInstnace->GetCharacterClassArray();

        int32 AICharacterCount = MainMenuGameMode->GetAICharacterCount();

        for (int i = 0; i < AICharacterCount; ++i)
        {
            int32 RandomIndex = FMath::RandRange(0, CharacterClassArray.Num() - 1);
            NewAICharacterClassArray.Add(CharacterClassArray[RandomIndex]);
        }

        const TArray<int32>& SelectedPlayers = MainMenuGameState->GetSelectedPlayers();
        int32 SelectedPlayerCount = SelectedPlayers.Num();

        // 현재 선택된 게임 모드에 대해 값을 넘김
        AMainMenuPlayerController* PlayerController = GetOwningPlayer<AMainMenuPlayerController>();
        if (PlayerController)
        {
            PlayerController->InitGameValue(AICharacterCount + SelectedPlayerCount, SelectedPlayerCount, 3, NewAICharacterClassArray);
        }
    }

    // 맵 선택 UI 생성
    if (UWorld* World = GetWorld())
    {
        UUserWidget* MapUserWidget = CreateWidget<UUserWidget>(World, LoadClass<UUserWidget>(nullptr, TEXT("/Game/Blueprints/UserWidgets/BP_MapUserWidget.BP_MapUserWidget_C")));
        if (MapUserWidget)
        {
            MapUserWidget->AddToViewport();
            RemoveFromParent();
        }
    }
}

void UCharacterSelectUserWidget::UpdateUI(const TArray<int32>& TargetPlayerCount, const TArray<int32>& SelectedPlayers)
{
    if (GetWorld())
    {
        AMainMenuGameState* MainMenuGameState = GetWorld()->GetGameState<AMainMenuGameState>();
        
        if (MainMenuGameState)
        {
            const TArray<int32>& SelectedPlayers = MainMenuGameState->GetSelectedPlayers();
        }
    }

    bool bIsCanStart = false;

    for (int32 e : TargetPlayerCount)
    {
        if (e == SelectedPlayers.Num())
        {
            bIsCanStart = true;
        }
    }

    if (bIsCanStart)
    {
        StartButton->SetVisibility(ESlateVisibility::Visible);
    }
    else
    {
        StartButton->SetVisibility(ESlateVisibility::Hidden);
    }
}