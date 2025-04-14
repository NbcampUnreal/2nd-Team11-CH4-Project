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

    // 플레이어가 스폰되어야할 위치를 가진 액터들
    TArray<AActor*> FoundActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnPointActor::StaticClass(), FoundActors);

    // 플레이어가 스폰되어야할 위치를 위해 인덱스를 가져옴
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

    // 레벨 이동이 된 플레이어의 수를 카운트
    // 입장 순서대로 현재 플레이어 스테이트에 번호를 부여
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

    // 모든 플레이어가 게임에 접속 된 경우
    if (TotalPlayerCount == PlayerJoinCount)
    {
        // 각 플레이어 스테이트에 플레이어 캐릭터의 목숨 설정
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
        // 모든 플레이어가 게임에 접속하지 않았으므로, 대기
        GetWorldTimerManager().ClearTimer(PlayerLoginTimerHandle);
        GetWorldTimerManager().SetTimer(PlayerLoginTimerHandle, this, &AFighterGamemode::AllPlayerLoginToGameStart, 1.f, false);
    }
}