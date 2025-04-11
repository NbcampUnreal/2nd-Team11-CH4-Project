#include "EnemyAnimInstance.h"
#include "EnemyCharacter.h"
#include "GameFramework/Character.h"
#include "EnemyCombatComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

//애니메이션을 매 프레임마다 갱신할 때 자동으로 호출되는 함수
void UEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    ACharacter* OwningCharacter = Cast<ACharacter>(TryGetPawnOwner());
    if (!OwningCharacter) return;

    Speed = OwningCharacter->GetVelocity().Size2D();
    bIsInAir = OwningCharacter->GetMovementComponent()->IsFalling();

    // 캐릭터 상태 업데이트 등 필요하면 여기서 처리
}

void UEnemyAnimInstance::PlayAttackMontage()
{
    if (!Montage_IsPlaying(AttackMontage))
    {
        Montage_Play(AttackMontage, 1.f);
    }
}

//AnimNotify_ 확인 후 에디터가 자동 매핑 해줌
void UEnemyAnimInstance::AnimNotify_HitCheck()
{
    AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(TryGetPawnOwner());
    if (Enemy && Enemy->CombatComponent)
    {
        Enemy->CombatComponent->DoHitTrace();
    }
}

void UEnemyAnimInstance::AnimNotify_AttackEnd()
{
    AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(TryGetPawnOwner());
    if (Enemy && Enemy->CombatComponent)
    {
        Enemy->CombatComponent->bIsAttacking = false;
    }
}

void UEnemyAnimInstance::AnimNotify_EndHit()
{
    //AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(TryGetPawnOwner());
    //if (Enemy)
    //{
    //    FVector lov = Enemy->GetActorLocation();

    //    lov.X -= 20;

    //    /*Enemy->SetActorLocation(lov);*/

    //    FVector KnockbackDirection = -Enemy->GetActorForwardVector();
    //    float KnockbackStrength = 300.f;

    //    Enemy->LaunchCharacter(KnockbackDirection * KnockbackStrength + FVector(0, 0, 200), true, true);
    //}
}
