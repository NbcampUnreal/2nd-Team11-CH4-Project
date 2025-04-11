#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EnemyAnimInstance.generated.h"

/*
* 애니메이션 블루프린트(C++)로 공격 트리거, 모션 등 관리
*/

UCLASS()
class SSBPROJECT_API UEnemyAnimInstance : public UAnimInstance
{
    GENERATED_BODY()

public:

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
    UAnimMontage* AttackMontage;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Animation")
    UAnimMontage* EndHitMontage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    float Speed;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    bool bIsInAir;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
    bool bIsAttacking;

    virtual void NativeUpdateAnimation(float DeltaSeconds) override;

    UFUNCTION()
    void AnimNotify_HitCheck();

    UFUNCTION()
    void AnimNotify_AttackEnd();

    UFUNCTION()
    void AnimNotify_EndHit();

    UFUNCTION(BlueprintCallable, Category = "Animation")
    void PlayAttackMontage();
};
