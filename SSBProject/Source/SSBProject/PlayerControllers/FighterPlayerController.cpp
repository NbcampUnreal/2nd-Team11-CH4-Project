// Fill out your copyright notice in the Description page of Project Settings.


#include "FighterPlayerController.h"
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
}

void AFighterPlayerController::AddMapping()
{
    // 매핑 추가
    if (ULocalPlayer* LocalPlayer = GetLocalPlayer())
    {
        if (UEnhancedInputLocalPlayerSubsystem* Subsystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>())
        {
            if (IMC)
            {
                // Subsystem을 통해 우리가 할당한 IMC를 활성화
                // 우선순위(Priority)는 0이 가장 높은 우선순위
                Subsystem->AddMappingContext(IMC, 0);
            }
        }
    }
}
