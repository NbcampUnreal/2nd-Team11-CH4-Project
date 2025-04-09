// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SSBBaseItem.h"
#include "SSBMineItem.generated.h"

/**
 * 
 */
UCLASS()
class SSBPROJECT_API ASSBMineItem : public ASSBBaseItem
{
	GENERATED_BODY()
public:
    ASSBMineItem();
protected:
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item|Component")
    USphereComponent* ExplosionCollision;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    float ExplosionDelay;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    float ExplosionRadius;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Mine")
    int ExplosionDamage;

    FTimerHandle ExplosionTimerHandle;

    virtual void ActivateItem(AActor* Activator) override;

    void Explode();
};
