// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBGameInstance.h"

void USSBGameInstance::Init()
{
    Super::Init();

    SelectedCharacterClass = nullptr;
    TotalPlayerCount = 0;

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
