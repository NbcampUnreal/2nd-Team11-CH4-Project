// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBGameInstance.h"

void USSBGameInstance::Init()
{
    Super::Init();

    TotalPlayerCount = 0;
    InitialStock = 0;

    //TEST
    TotalPlayerCount = 1;
    InitialStock = 3;
}

void USSBGameInstance::ServerMapTravel_Implementation(const FString& MapName)
{
    if (GetWorld() && GetWorld()->GetAuthGameMode())
    {
        FString Command = FString::Printf(TEXT("%s?listen"), *MapName);
        GetWorld()->ServerTravel(Command);
    }
}

TSubclassOf<APawn> USSBGameInstance::GetSelectedCharacterClassMap(FString KeyClientName) const
{
    const TSubclassOf<APawn>* Found = SelectedCharacterClassMap.Find(KeyClientName);
    return Found ? *Found : nullptr;
}

void USSBGameInstance::SetSelectedCharacterClassMap(FString KeyClientName, TSubclassOf<APawn> NewClass)
{
    if (NewClass)
    {
        SelectedCharacterClassMap.FindOrAdd(KeyClientName) = NewClass;
    }
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
