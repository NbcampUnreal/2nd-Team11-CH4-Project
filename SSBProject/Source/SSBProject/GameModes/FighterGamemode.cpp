// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterGamemode.h"
#include "SSBGameInstance.h"
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

void AFighterGamemode::HandlePlayerCharacterClass(APlayerController* Player, TSubclassOf<APawn> CharacterClass)
{
    CharacterClassMap.FindOrAdd(Player) = CharacterClass;

    AFighterGameState* FighterGameState = GetGameState<AFighterGameState>();

    int32 TotalPlayerCount = FighterGameState->GetTotalPlayerCount();
    int32 PlayerJoinCount = FighterGameState->GetPlayerJoinCount();

    if (TotalPlayerCount == PlayerJoinCount)
    {
        SpawnPlayerCharacters();
    }
}

void AFighterGamemode::SpawnPlayerCharacters()
{
    // Pawn들의 BeginPlay이벤트가 차례대로 호출되고 플레이어 컨트롤러들의 OnPossecc 이벤트가 따로 한번에 호출 될 수 있도록 분리
    TMap<APlayerController*, TObjectPtr<APawn>> SpawnCharacter;

    // 플레이어가 빙의 될 폰 스폰하기
    for (auto e : CharacterClassMap)
    {
        APlayerController* Player = e.Key;
        TSubclassOf<APawn> CharacterClass = e.Value;

        AFighterPlayerState* FighterPlayerState = Cast<AFighterPlayerState>(Player->PlayerState);

        // 바로 스폰 시도 가능 (이미 로그인된 경우)
        if (CharacterClass && Player && !Player->GetPawn() && FighterPlayerState)
        {
            // 플레이어가 스폰되어야할 위치를 가진 액터들
            TArray<AActor*> FoundActors;
            UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnPointActor::StaticClass(), FoundActors);

            // 플레이어가 스폰되어야할 위치를 위해 인덱스를 가져옴
            int32 PlayerIndex = FighterPlayerState->GetPlayerIndex();

            FVector SpawnLocation = FVector(0.f, 0.f, 0.f);
            FRotator SpawnRotation = FRotator::ZeroRotator;

            if (FoundActors.Num() > PlayerIndex)
            {
                SpawnLocation = FoundActors[PlayerIndex]->GetActorLocation();
                SpawnRotation = FoundActors[PlayerIndex]->GetActorRotation();
            }

            FActorSpawnParameters SpawnParams;
            SpawnParams.Owner = Player;

            APawn* NewPawn = GetWorld()->SpawnActor<APawn>(*CharacterClass, SpawnLocation, SpawnRotation, SpawnParams);
            SpawnCharacter.Add(Player, NewPawn);
        }
    }

    for (auto e : SpawnCharacter)
    {
        APlayerController* CurPlayerController = e.Key;
        TObjectPtr<APawn> CurPawn = e.Value;

        if (CurPlayerController && CurPawn)
        {
            CurPlayerController->Possess(CurPawn);
        }
    }
}


