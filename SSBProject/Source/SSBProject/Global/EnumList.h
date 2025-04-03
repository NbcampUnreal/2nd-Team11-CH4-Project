// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnumList.generated.h"

UENUM(BlueprintType)
enum class EMaps : uint8
{
    None UMETA(DisplayName = "None")

};

UENUM(BlueprintType)
enum class EGameModes : uint8
{
    None UMETA(DisplayName = "None"),
    Scenario UMETA(DisplayName = "Scenario"),
    PVP UMETA(DisplayName = "PVP"),
    PVE UMETA(DisplayName = "PVE")
};

UENUM(BlueprintType)
enum class ECharacters : uint8
{
    None UMETA(DisplayName = "None"),
    Fighter UMETA(DisplayName = "Fighter"),
    Random UMETA(DisplayName = "Random"),
};