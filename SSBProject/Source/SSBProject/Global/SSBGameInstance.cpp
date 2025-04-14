// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBGameInstance.h"

void USSBGameInstance::Init()
{
    Super::Init();

    TotalCharacterCount = 0;
    TotalPlayerCount = 0;
    InitialStock = 0;

    //TEST
    TotalCharacterCount = 3;
    TotalPlayerCount = 2;
    InitialStock = 3;

    AICharacterClassArray.Add(TESTSelectedCharacterClass);
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

TSubclassOf<APawn> USSBGameInstance::GetAICharacterClassArray(int Index)
{
    return AICharacterClassArray[Index];
}

void USSBGameInstance::SetAICharacterClassArray(TArray<TSubclassOf<APawn>> NewAICharacterClassArray)
{
    AICharacterClassArray = NewAICharacterClassArray;
}

int32 USSBGameInstance::GetTotalCharacterCount()
{
    return TotalCharacterCount;
}

void USSBGameInstance::SetTotalCharacterCount(int32 NewTotalCharacterCount)
{
    TotalCharacterCount = NewTotalCharacterCount;
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
