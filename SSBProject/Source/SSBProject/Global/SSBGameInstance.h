// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SSBGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SSBPROJECT_API USSBGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
    virtual void Init() override;

    UFUNCTION(BlueprintCallable, Server, Reliable)
    void ServerMapTravel(const FString& MapName);
	
public:
    UFUNCTION(BlueprintCallable)
    TSubclassOf<APawn> GetSelectedCharacterClass() const;
    UFUNCTION(BlueprintCallable)
    void SetSelectedCharacterClass(TSubclassOf<APawn> NewClass);

    UFUNCTION(BlueprintCallable)
    int32 GetTotalPlayerCount();
    UFUNCTION(BlueprintCallable)
    void SetTotalPlayerCount(int32 NewTotalPlayerCount);

protected:
    // ������ ĳ����
	UPROPERTY(BlueprintReadOnly, Category = "Character")
	TSubclassOf<APawn> SelectedCharacterClass;

    // �� �÷��̾� ��
    UPROPERTY(BlueprintReadOnly, Category = "Player")
    int32 TotalPlayerCount;
};
