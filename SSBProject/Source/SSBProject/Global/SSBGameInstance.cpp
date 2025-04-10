// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBGameInstance.h"

void USSBGameInstance::Init()
{
    Super::Init();

    SelectedCharacterClass = nullptr;
    TotalPlayerCount = 0;
    InitialStock = 0;

    //TEST
    TotalPlayerCount = 2;
    SelectedCharacterClass = TESTSelectedCharacterClass;
    InitialStock = 3;
}

void USSBGameInstance::ServerMapTravel_Implementation(const FString& MapName)
{
    if (GetWorld() && GetWorld()->GetAuthGameMode())
    {
        FString Command = FString::Printf(TEXT("servertravel %s"), *MapName);
        GetWorld()->ServerTravel(Command);
    }
}

TSubclassOf<APawn> USSBGameInstance::GetSelectedCharacterClass() const
{
    return SelectedCharacterClass;
}

void USSBGameInstance::SetSelectedCharacterClass(TSubclassOf<APawn> NewClass)
{
    SelectedCharacterClass = NewClass;
}

int32 USSBGameInstance::GetTotalPlayerCount()
{
    return TotalPlayerCount;
}

void USSBGameInstance::SetTotalPlayerCount(int32 NewTotalPlayerCount)
{
    TotalPlayerCount = NewTotalPlayerCount;
}

int32 USSBGameInstance::GetInitialStock()
{
    return InitialStock;
}

void USSBGameInstance::SetInitialStock(int32 NewInitialStock)
{
    InitialStock = NewInitialStock;
}
