// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SSBItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USSBItemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SSBPROJECT_API ISSBItemInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
    virtual void OnItemOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult) = 0;
    virtual void OnItemEndOverlap(UPrimitiveComponent* OverlappedComp,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex) = 0;
    virtual void ActivateItem(AActor* Activator) = 0;
    virtual FName GetItemType() const = 0;
};
