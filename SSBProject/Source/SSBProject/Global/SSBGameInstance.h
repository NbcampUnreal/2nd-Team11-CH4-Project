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
    TSubclassOf<APawn> GetAICharacterClassArray(int Index);
    UFUNCTION(BlueprintCallable)
    void SetAICharacterClassArray(TArray<TSubclassOf<APawn>> NewAICharacterClassArray);

    UFUNCTION(BlueprintCallable)
    int32 GetTotalCharacterCount();
    UFUNCTION(BlueprintCallable)
    void SetTotalCharacterCount(int32 NewTotalCharacterCount);

    UFUNCTION(BlueprintCallable)
    int32 GetTotalPlayerCount();
    UFUNCTION(BlueprintCallable)
    void SetTotalPlayerCount(int32 NewTotalPlayerCount);

    UFUNCTION()
    void SetIsAIArray(int32 Index, bool NewbIsAI);

    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetInitialStock();
    UFUNCTION(BlueprintCallable)
    void SetInitialStock(int32 NewInitialStock);

    //TEST
    UPROPERTY(EditAnywhere)
    TSubclassOf<APawn> TESTSelectedCharacterClass;

protected:
    // 선택된 캐릭터 목록
    UPROPERTY(BlueprintReadOnly, Category = "Character")
    TMap<FString, TSubclassOf<APawn>> SelectedCharacterClassMap;

    // 스폰되어야 할 AI 캐릭터 목록
    TArray<TSubclassOf<APawn>> AICharacterClassArray;

    // 총 캐릭터 수
    UPROPERTY(BlueprintReadOnly, Category = "Player")
    int32 TotalCharacterCount;

    // 총 플레이어 수
    UPROPERTY(BlueprintReadOnly, Category = "Player")
    int32 TotalPlayerCount;

    // AI가 되어야할 캐릭터 인덱스
    UPROPERTY(BlueprintReadOnly, Category = "AI")
    TArray<bool> bIsAIArray;

    // Stock 모드에서 사용할 Stock 수
    UPROPERTY(BlueprintReadOnly, Category = "Stock")
    int32 InitialStock;
};
