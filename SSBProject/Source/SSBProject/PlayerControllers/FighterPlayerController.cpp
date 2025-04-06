// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterPlayerController.h"
#include "SSBGameInstance.h"
#include "FighterGamemode.h"
#include "FighterCharacter.h"
#include "EnhancedInputSubsystems.h"

AFighterPlayerController::AFighterPlayerController()
{
    IMC = nullptr;
    LeftRightAction = nullptr;
}

void AFighterPlayerController::BeginPlay()
{
    Super::BeginPlay();

    AddMapping();

    if (IsLocalController())
    {
        if (const USSBGameInstance* SSBGI = GetGameInstance<USSBGameInstance>())
        {
            if (SSBGI->GetSelectedCharacterClass())
            {
                Server_SetSelectedCharacter(SSBGI->GetSelectedCharacterClass());
            }
        }
    }
}

void AFighterPlayerController::Server_SetSelectedCharacter_Implementation(TSubclassOf<APawn> InClass)
{
    if (AFighterGamemode* FighterGamemode = GetWorld()->GetAuthGameMode<AFighterGamemode>())
    {
        FighterGamemode->HandlePlayerCharacterClass(this, InClass);
    }
}

void AFighterPlayerController::AddMapping()
{
    // ���� �߰�
    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (IMC)
            {
                // Subsystem�� ���� �츮�� �Ҵ��� IMC�� Ȱ��ȭ
                // �켱����(Priority)�� 0�� ���� ���� �켱����
                Subsystem->AddMappingContext(IMC, 0);
            }
        }
    }
}
