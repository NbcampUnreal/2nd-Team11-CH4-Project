#pragma once

#include "CoreMinimal.h"
#include "AIController.h" 
#include "GameFramework/PlayerController.h"
#include "GenericTeamAgentInterface.h"
#include "EnemyAIController.generated.h"

/*
* 플레이어 추적 및 행동 결정
*/
UCLASS()
class SSBPROJECT_API AEnemyAIController : public APlayerController, public IGenericTeamAgentInterface
{
    GENERATED_BODY()

public:
    AEnemyAIController();

    float DistanceX;
    float MoveDir;

    virtual void BeginPlay() override;

    virtual void Tick(float DeltaTime) override;

    //virtual ETeamAttitude::Type GetTeamAttitudeTowards(const AActor& Other) const override;

    APawn* GetTargetPlayer() const;
};
