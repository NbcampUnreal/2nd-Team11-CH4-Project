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

UENUM(BlueprintType)
enum class EBuffer : uint8
{
	None UMETA(DisplayName = "None"),
	Attack UMETA(DisplayName = "Attack"),
	Special UMETA(DisplayName = "Special"),
	Jump UMETA(DisplayName = "Jump"),
	Sheild UMETA(DisplayName = "Sheild")
};

UENUM(BlueprintType)
enum class EAbilityTypes : uint8
{
	None UMETA(DisplayName = "None"),
	Basic UMETA(DisplayName = "Basic"),
	Special UMETA(DisplayName = "Special"),
	Air UMETA(DisplayName = "Air"),
	Smash UMETA(DisplayName = "Smash"),
	Super UMETA(DisplayName = "Super"),
	Dodge UMETA(DisplayName = "Dodge"),
	Taunt UMETA(DisplayName = "Taunt"),
	Ledge UMETA(DisplayName = "Ledge"),
	Throw UMETA(DisplayName = "Throw"),
	Prone UMETA(DisplayName = "Prone"),
	Grab UMETA(DisplayName = "Grab"),
	Other UMETA(DisplayName = "Other")
};

UENUM(BlueprintType)
enum class EAttackTable : uint8
{
	Attack1 UMETA(DisplayName = "Attack1"),
	Attack2 UMETA(DisplayName = "Attack2"),
	Attack3 UMETA(DisplayName = "Attack3"),
	Attack4 UMETA(DisplayName = "Attack4"),
	Attack5 UMETA(DisplayName = "Attack5"),
	Attack6 UMETA(DisplayName = "Attack6"),
	Attack7 UMETA(DisplayName = "Attack7"),
	Attack8 UMETA(DisplayName = "Attack8"),
	Attack9 UMETA(DisplayName = "Attack9"),
	Attack10 UMETA(DisplayName = "Attack10"),
	Attack11 UMETA(DisplayName = "Attack11"),
	Attack12 UMETA(DisplayName = "Attack12"),
	Attack13 UMETA(DisplayName = "Attack13"),
	Attack14 UMETA(DisplayName = "Attack14"),
	Attack15 UMETA(DisplayName = "Attack15"),
	Attack16 UMETA(DisplayName = "Attack16"),
	Attack17 UMETA(DisplayName = "Attack17"),
	Attack18 UMETA(DisplayName = "Attack18"),
	Attack19 UMETA(DisplayName = "Attack19"),
	Attack20 UMETA(DisplayName = "Attack20"),
	Attack21 UMETA(DisplayName = "Attack21"),
	Attack22 UMETA(DisplayName = "Attack22"),
	Attack23 UMETA(DisplayName = "Attack23"),
	Attack24 UMETA(DisplayName = "Attack24"),
	Attack25 UMETA(DisplayName = "Attack25"),
	Attack26 UMETA(DisplayName = "Attack26"),
	Attack27 UMETA(DisplayName = "Attack27"),
	Attack28 UMETA(DisplayName = "Attack28"),
	Attack29 UMETA(DisplayName = "Attack29"),
	Attack30 UMETA(DisplayName = "Attack30")
};

UENUM(BlueprintType)
enum class EAttacks : uint8
{
	TiltUp UMETA(DisplayName = "TiltUp"),
	TiltDown UMETA(DisplayName = "TiltDown"),
	TiltForward UMETA(DisplayName = "TiltForward"),
	TiltBack UMETA(DisplayName = "TiltBack"),
	Nuetral UMETA(DisplayName = "Nuetral"),
	AirUp UMETA(DisplayName = "AirUp"),
	AirDown UMETA(DisplayName = "AirDown"),
	AirBack UMETA(DisplayName = "AirBack"),
	AirForward UMETA(DisplayName = "AirForward"),
	AirNuetral UMETA(DisplayName = "AirNuetral"),
	SpecialUP UMETA(DisplayName = "SpecialUP"),
	SpecialDown UMETA(DisplayName = "SpecialDown"),
	SpecialForward UMETA(DisplayName = "SpecialForward"),
	SpecialBack UMETA(DisplayName = "SpecialBack"),
	SpecialNuetral UMETA(DisplayName = "SpecialNuetral"),
	SmashUP UMETA(DisplayName = "SmashUP"),
	SmashDown UMETA(DisplayName = "SmashDown"),
	SmashForward UMETA(DisplayName = "SmashForward"),
	SmashBack UMETA(DisplayName = "SmashBack"),
	Grab UMETA(DisplayName = "Grab"),
	ThrowUP UMETA(DisplayName = "ThrowUP"),
	ThrowDown UMETA(DisplayName = "ThrowDown"),
	ThrowForward UMETA(DisplayName = "ThrowForward"),
	ThrowBack UMETA(DisplayName = "ThrowBack"),
	Pumble UMETA(DisplayName = "Pumble"),
	LedgeAttack UMETA(DisplayName = "LedgeAttack"),
	ProneAttack UMETA(DisplayName = "ProneAttack"),
	DodgeSpot UMETA(DisplayName = "DodgeSpot"),
	DodgeAir UMETA(DisplayName = "DodgeAir"),
	DodgeBack UMETA(DisplayName = "DodgeBack"),
	DodgeForward UMETA(DisplayName = "DodgeForward"),
	Super UMETA(DisplayName = "Super"),
	None UMETA(DisplayName = "None")
};

UENUM(BlueprintType)
enum class ECollisionTypes : uint8
{
	Normal UMETA(DisplayName = "Normal"),
	Sweet UMETA(DisplayName = "Sweet"),
	Sour UMETA(DisplayName = "Sour"),
	Spike UMETA(DisplayName = "Spike"),
	Metior UMETA(DisplayName = "Metior"),
	Multi UMETA(DisplayName = "Multi")
};

UENUM(BlueprintType)
enum class EDirections : uint8
{
	None UMETA(DisplayName = "None"),
	Up UMETA(DisplayName = "Up"),
	Down UMETA(DisplayName = "Down"),
	Back UMETA(DisplayName = "Back"),
	Forward UMETA(DisplayName = "Forward")
};

UENUM(BlueprintType)
enum class EEnableDisable : uint8
{
	Enabled UMETA(DisplayName = "Enabled"),
	Disabled UMETA(DisplayName = "Disabled"),
	Custom UMETA(DisplayName = "Custom")
};

UENUM(BlueprintType)
enum class EFaceing : uint8
{
	Left UMETA(DisplayName = "Left"),
	Right UMETA(DisplayName = "Right")
};

UENUM(BlueprintType)
enum class EHitStates : uint8
{
	Normal UMETA(DisplayName = "Normal"),
	Intangible UMETA(DisplayName = "Intangible"),
	Invincible UMETA(DisplayName = "Invincible"),
	Armor UMETA(DisplayName = "Armor"),
	Shield UMETA(DisplayName = "Shield")
};

UENUM(BlueprintType)
enum class EPlayerStates : uint8
{
	Idle UMETA(DisplayName = "Idle"),
	WalkOrRun UMETA(DisplayName = "Walk/Run"),
	Crouch UMETA(DisplayName = "Crouch"),
	Sprint UMETA(DisplayName = "Sprint"),
	Jump UMETA(DisplayName = "Jump"),
	Fall UMETA(DisplayName = "Fall"),
	Hit UMETA(DisplayName = "Hit"),
	Launch UMETA(DisplayName = "Launch"),
	Ledge UMETA(DisplayName = "Ledge"),
	Dead UMETA(DisplayName = "Dead"),
	Shiled UMETA(DisplayName = "Shiled"),
	Tumble UMETA(DisplayName = "Tumble"),
	ShildTumble UMETA(DisplayName = "ShildTumble"),
	Prone UMETA(DisplayName = "Prone"),
	Stun UMETA(DisplayName = "Stun"),
	Dizzy UMETA(DisplayName = "Dizzy"),
	Ability UMETA(DisplayName = "Ability"),
	Dodge UMETA(DisplayName = "Dodge"),
	FreeFall UMETA(DisplayName = "FreeFall"),
	Held UMETA(DisplayName = "Held"),
	Hold UMETA(DisplayName = "Hold")
};

UENUM(BlueprintType)
enum class EShape : uint8
{
	Sphere UMETA(DisplayName = "Sphere"),
	Box UMETA(DisplayName = "Box"),
	Pill UMETA(DisplayName = "Pill")
};