#include "EnemyCombatComponent.h"
#include "EnemyCharacter.h"
#include "EnemyAnimInstance.h"
#include "GameFramework/Actor.h"
#include "GameFramework/CharacterMovementComponent.h"

UEnemyCombatComponent::UEnemyCombatComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    bIsAttacking = false;
    LastAttackTime = 0.f;
    AttackCooldown = 1.2f;
}

void UEnemyCombatComponent::BeginPlay()
{
    Super::BeginPlay();

    OwnerEnemy = Cast<AEnemyCharacter>(GetOwner());
}

void UEnemyCombatComponent::TryAttack()
{
    if (bIsAttacking) return;

    float CurrentTime = GetWorld()->TimeSeconds;
    if (CurrentTime - LastAttackTime < AttackCooldown)
        return;

    UEnemyAnimInstance* AnimInstance = Cast<UEnemyAnimInstance>(OwnerEnemy->GetMesh()->GetAnimInstance());
    if (AnimInstance->AttackMontage)
    {
        bIsAttacking = true;
        LastAttackTime = CurrentTime;

        AnimInstance->Montage_Play(AnimInstance->AttackMontage);
    }
}

void UEnemyCombatComponent::DoHitTrace()
{
    FVector Start = OwnerEnemy->GetActorLocation() + FVector(0, 0, 50);
    FVector End = Start + OwnerEnemy->GetActorForwardVector() * 150;

    FHitResult Hit;
    FCollisionQueryParams Params;
    Params.AddIgnoredActor(OwnerEnemy);

    bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Pawn, Params);

    if (bHit && Hit.GetActor())
    {
        AEnemyCharacter* Target = Cast<AEnemyCharacter>(Hit.GetActor());
        if (Target)
        {
            Target->PlayHitReaction(Start);
            FVector KnockbackDirection = -Target->GetActorForwardVector();
            KnockbackDirection.Z = 0.0f;
            float KnockbackStrength = 300.f;

            Target->LaunchCharacter(KnockbackDirection * KnockbackStrength, true, false);
        }
    }
}



