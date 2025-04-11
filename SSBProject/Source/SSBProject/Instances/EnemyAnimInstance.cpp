#include "EnemyAnimInstance.h"
#include "EnemyCharacter.h"
#include "GameFramework/Character.h"
#include "EnemyCombatComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

//�ִϸ��̼��� �� �����Ӹ��� ������ �� �ڵ����� ȣ��Ǵ� �Լ�
void UEnemyAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
    Super::NativeUpdateAnimation(DeltaSeconds);

    ACharacter* OwningCharacter = Cast<ACharacter>(TryGetPawnOwner());
    if (!OwningCharacter) return;

    Speed = OwningCharacter->GetVelocity().Size2D();
    bIsInAir = OwningCharacter->GetMovementComponent()->IsFalling();

    // ĳ���� ���� ������Ʈ �� �ʿ��ϸ� ���⼭ ó��
}

void UEnemyAnimInstance::PlayAttackMontage()
{
    if (!Montage_IsPlaying(AttackMontage))
    {
        Montage_Play(AttackMontage, 1.f);
    }
}

//AnimNotify_ Ȯ�� �� �����Ͱ� �ڵ� ���� ����
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
