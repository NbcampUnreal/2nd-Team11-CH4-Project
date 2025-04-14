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
    TSubclassOf<APawn> GetSelectedCharacterClassMap(FString KeyClientName) const;
    UFUNCTION(BlueprintCallable)
    void SetSelectedCharacterClassMap(FString KeyClientName, TSubclassOf<APawn> NewClass);

    UFUNCTION(BlueprintCallable)
    int32 GetTotalPlayerCount();
    UFUNCTION(BlueprintCallable)
    void SetTotalPlayerCount(int32 NewTotalPlayerCount);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetInitialStock();
    UFUNCTION(BlueprintCallable)
    void SetInitialStock(int32 NewInitialStock);

    UPROPERTY(EditAnywhere)
    TSubclassOf<APawn> TESTSelectedCharacterClass;

protected:
    // ���õ� ĳ���� ���
    UPROPERTY(BlueprintReadOnly, Category = "Character")
    TMap<FString, TSubclassOf<APawn>> SelectedCharacterClassMap;

    // ������ ĳ����
	UPROPERTY(BlueprintReadOnly, Category = "Character")
	TSubclassOf<APawn> SelectedCharacterClass;

    // �� �÷��̾� ��
    UPROPERTY(BlueprintReadOnly, Category = "Player")
    int32 TotalPlayerCount;

    // Stock ��忡�� ����� Stock ��
    UPROPERTY(BlueprintReadOnly, Category = "Stock")
    int32 InitialStock;
};
