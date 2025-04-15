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
    const TArray<TSubclassOf<APawn>> GetCharacterClassArray() const;

    UFUNCTION(BlueprintCallable)
    TSubclassOf<APawn> GetSelectedCharacterClassMap(FString KeyClientName) const;
    UFUNCTION(BlueprintCallable)
    void SetSelectedCharacterClassMap(FString KeyClientName, TSubclassOf<APawn> NewClass);

    UFUNCTION(BlueprintCallable)
    TSubclassOf<APawn> GetSelectedAICharacterClassArray(int Index);
    UFUNCTION(BlueprintCallable)
    void SetSelectedAICharacterClassArray(TArray<TSubclassOf<APawn>> NewAICharacterClassArray);

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

protected:
    // ĳ���� Ŭ�������� ����� �迭
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Character")
    TArray<TSubclassOf<APawn>> CharacterClassArray;

    // ���õ� ĳ���� ���
    UPROPERTY(BlueprintReadOnly, Category = "Character")
    TMap<FString, TSubclassOf<APawn>> SelectedCharacterClassMap;

    // �����Ǿ�� �� AI ĳ���� ���
    UPROPERTY(BlueprintReadOnly, Category = "Character")
    TArray<TSubclassOf<APawn>> SelectedAICharacterClassArray;

    // �� ĳ���� ��
    UPROPERTY(BlueprintReadOnly, Category = "Player")
    int32 TotalCharacterCount;

    // �� �÷��̾� ��
    UPROPERTY(BlueprintReadOnly, Category = "Player")
    int32 TotalPlayerCount;

    // AI�� �Ǿ���� ĳ���� �ε���
    UPROPERTY(BlueprintReadOnly, Category = "AI")
    TArray<bool> bIsAIArray;

    // Stock ��忡�� ����� Stock ��
    UPROPERTY(BlueprintReadOnly, Category = "Stock")
    int32 InitialStock;
};
