#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyCombatComponent.generated.h"

/*
* ���� ���� �и� (�Ÿ� �Ǵ�, ����, ȸ�� �� ���� ��ƾ ó��)
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
