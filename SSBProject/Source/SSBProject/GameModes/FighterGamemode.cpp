// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterGamemode.h"
#include "SSBGameInstance.h"
#include "FighterPlayerController.h"
#include "FighterPlayerState.h"
#include "FighterGameState.h"
#include "Kismet/GamePlayStatics.h"
#include "SpawnPointActor.h"

AFighterGamemode::AFighterGamemode()
{
    DefaultPawnClass = nullptr;
}

void AFighterGamemode::InitGameState()
{
    Super::InitGameState();

    AFighterGameState* FighterGameState = GetGameState<AFighterGameState>();

    if (FighterGameState)
    {
        if (USSBGameInstance* SSBGI = GetGameInstance<USSBGameInstance>())
        {
            FighterGameState->SetTotalPlayerCount(SSBGI->GetTotalPlayerCount());
        }
    }
}

void AFighterGamemode::StartPlay()
{
    Super::StartPlay();
}

UClass* AFighterGamemode::GetDefaultPawnClassForController_Implementation(AController* InController)
{
    AFighterPlayerController* CurPlayerController = Cast<AFighterPlayerController>(InController);
    AFighterPlayerState* FighterPlayerState = Cast<AFighterPlayerState>(CurPlayerController->PlayerState);

    USSBGameInstance* SSBGameInstance = GetGameInstance<USSBGameInstance>();
    TSubclassOf<APawn> ChosenClass = SSBGameInstance->GetSelectedCharacterClassMap(FighterPlayerState->GetPlayerName());

    return ChosenClass;
}

APawn* AFighterGamemode::SpawnDefaultPawnFor_Implementation(AController* NewPlayer, AActor* StartSpot)
{
    AFighterPlayerController* CurPlayerController = Cast<AFighterPlayerController>(NewPlayer);
    AFighterPlayerState* FighterPlayerState = Cast<AFighterPlayerState>(CurPlayerController->PlayerState);

    USSBGameInstance* SSBGameInstance = GetGameInstance<USSBGameInstance>();
    TSubclassOf<APawn> ChosenClass = SSBGameInstance->GetSelectedCharacterClassMap(FighterPlayerState->GetPlayerName());

    // �÷��̾ �����Ǿ���� ��ġ�� ���� ���͵�
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnPointActor::StaticClass(), FoundActors);

    // �÷��̾ �����Ǿ���� ��ġ�� ���� �ε����� ������
    int32 PlayerIndex = FighterPlayerState->GetPlayerIndex();

    FTransform SpawnTransform = FTransform::Identity;

    if (FoundActors.Num() > PlayerIndex)
    {
        SpawnTransform = FoundActors[PlayerIndex]->GetActorTransform();
    }

    APawn* SpawnedPawn = GetWorld()->SpawnActor<APawn>(ChosenClass, SpawnTransform);

    NewPlayer->Possess(SpawnedPawn);

    return SpawnedPawn;
}

void AFighterGamemode::BeginPlay()
{
    Super::BeginPlay();

    GetWorldTimerManager().SetTimer(PlayerLoginTimerHandle, this, &AFighterGamemode::AllPlayerLoginToGameStart, 1.f, false);
}

void AFighterGamemode::PostLogin(APlayerController* NewPlayer)
{
    Super::PostLogin(NewPlayer);

    if (!NewPlayer)
    {
        return;
    }

    AFighterGameState* FighterGameState = GetGameState<AFighterGameState>();
    AFighterPlayerState* FighterPlayerState = Cast<AFighterPlayerState>(NewPlayer->PlayerState);

    // ���� �̵��� �� �÷��̾��� ���� ī��Ʈ
    // ���� ������� ���� �÷��̾� ������Ʈ�� ��ȣ�� �ο�
    if (FighterGameState && FighterPlayerState)
    {
        FighterPlayerState->SetPlayerIndex(FighterGameState->GetPlayerJoinCount());
        FighterGameState->SetPlayerJoinCount(FighterGameState->GetPlayerJoinCount() + 1);
    }
}

void AFighterGamemode::AllPlayerLoginToGameStart()
{
    AFighterGameState* FighterGameState = GetGameState<AFighterGameState>();

    int32 TotalPlayerCount = FighterGameState->GetTotalPlayerCount();
    int32 PlayerJoinCount = FighterGameState->GetPlayerJoinCount();

    // ��� �÷��̾ ���ӿ� ���� �� ���
    if (TotalPlayerCount == PlayerJoinCount)
    {
        // �� �÷��̾� ������Ʈ�� �÷��̾� ĳ������ ��� ����
        for (TObjectPtr<APlayerState> PlayerState : FighterGameState->PlayerArray)
        {
            TObjectPtr<AFighterPlayerState> FighterPlayerState = Cast<AFighterPlayerState>(PlayerState);
            USSBGameInstance* SSBGameInstance = GetGameInstance<USSBGameInstance>();
            if (FighterPlayerState && SSBGameInstance)
            {
                FighterPlayerState->SetStock(SSBGameInstance->GetInitialStock());
            }
        }
    }
    else
    {
        // ��� �÷��̾ ���ӿ� �������� �ʾ����Ƿ�, ���
        GetWorldTimerManager().ClearTimer(PlayerLoginTimerHandle);
        GetWorldTimerManager().SetTimer(PlayerLoginTimerHandle, this, &AFighterGamemode::AllPlayerLoginToGameStart, 1.f, false);
    }
}