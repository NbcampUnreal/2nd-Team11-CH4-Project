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

    // ���� �̵��� �� �÷��̾��� ���� ī��Ʈ
    // ���� ������� ���� �÷��̾� ������Ʈ�� ��ȣ�� �ο�
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
    // Pawn���� BeginPlay�̺�Ʈ�� ���ʴ�� ȣ��ǰ� �÷��̾� ��Ʈ�ѷ����� OnPossecc �̺�Ʈ�� ���� �ѹ��� ȣ�� �� �� �ֵ��� �и�
    TMap<APlayerController*, TObjectPtr<APawn>> SpawnCharacter;

    // �÷��̾ ���� �� �� �����ϱ�
    for (auto e : CharacterClassMap)
    {
        APlayerController* Player = e.Key;
        TSubclassOf<APawn> CharacterClass = e.Value;

        AFighterPlayerState* FighterPlayerState = Cast<AFighterPlayerState>(Player->PlayerState);

        // �ٷ� ���� �õ� ���� (�̹� �α��ε� ���)
        if (CharacterClass && Player && !Player->GetPawn() && FighterPlayerState)
        {
            // �÷��̾ �����Ǿ���� ��ġ�� ���� ���͵�
            TArray<AActor*> FoundActors;
            UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnPointActor::StaticClass(), FoundActors);

            // �÷��̾ �����Ǿ���� ��ġ�� ���� �ε����� ������
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


