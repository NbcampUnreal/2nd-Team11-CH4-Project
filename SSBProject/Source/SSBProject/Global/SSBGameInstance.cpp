// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBGameInstance.h"

void USSBGameInstance::Init()
{
    Super::Init();

    TotalCharacterCount = 0;
    TotalPlayerCount = 0;
    InitialStock = 0;
    bIsAIArray.SetNum(4);
    for (int i = 0; i < bIsAIArray.Num(); ++i)
    {
        bIsAIArray[i] = false;
    }
}

void USSBGameInstance::ServerMapTravel_Implementation(const FString& MapName)
{
    if (GetWorld() && GetWorld()->GetAuthGameMode())
    {
        FString Command = FString::Printf(TEXT("%s?listen"), *MapName);
        GetWorld()->ServerTravel(Command);
    }
}

const TArray<TSubclassOf<APawn>> USSBGameInstance::GetCharacterClassArray() const
{
    return CharacterClassArray;
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

TSubclassOf<APawn> USSBGameInstance::GetSelectedAICharacterClassArray(int Index)
{
    return SelectedAICharacterClassArray[Index];
}

void USSBGameInstance::SetSelectedAICharacterClassArray(TArray<TSubclassOf<APawn>> NewAICharacterClassArray)
{
    SelectedAICharacterClassArray = NewAICharacterClassArray;
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

void USSBGameInstance::SetIsAIArray(int32 Index, bool NewbIsAI)
{
    bIsAIArray[Index] = NewbIsAI;
}

int32 USSBGameInstance::GetInitialStock()
{
    return InitialStock;
}

void USSBGameInstance::SetInitialStock(int32 NewInitialStock)
{
    InitialStock = NewInitialStock;
}
