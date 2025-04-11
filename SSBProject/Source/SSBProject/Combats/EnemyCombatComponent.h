#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyCombatComponent.generated.h"

/*
* 전투 로직 분리 (거리 판단, 공격, 회피 등 전투 루틴 처리)
*/
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SSBPROJECT_API UEnemyCombatComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UEnemyCombatComponent();

    UFUNCTION(BlueprintCallable, Category = "Combat")
    void DoHitTrace();

    bool bIsAttacking;
    float LastAttackTime;
    float AttackCooldown;

    UPROPERTY(EditDefaultsOnly, Category = "Ability")
    TSubclassOf<AActor> AirBackAbilityClass;

    class AEnemyCharacter* OwnerEnemy;

    void TryAttack();

    virtual void BeginPlay() override;
};
