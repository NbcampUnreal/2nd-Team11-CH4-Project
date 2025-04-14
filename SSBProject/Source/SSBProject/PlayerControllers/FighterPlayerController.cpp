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

    // UI ���� �Է� ��� ���� (���콺 Ŀ���� ǥ��)
    FInputModeGameOnly InputMode;
    SetInputMode(InputMode);
    bShowMouseCursor = false;

    AddMapping();
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
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("Input mapping skipped: GetLocalPlayer() is null"));
    }
}
