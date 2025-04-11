#include "EnemyCharacter.h"
#include "EnemyCombatComponent.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "AttributeSet.h"

AEnemyCharacter::AEnemyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));

    CombatComponent = CreateDefaultSubobject<UEnemyCombatComponent>(TEXT("CombatComponent"));
}

void AEnemyCharacter::BeginPlay()
{
    Super::BeginPlay();

    // ���� �ʿ��� �ʱ�ȭ ����
}

void AEnemyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector Velocity = GetVelocity();

    if (FMath::Abs(Velocity.X) > 5.f) // ���� ���� ���°� �ƴ� ��
    {
        float DesiredYaw = Velocity.X > 0 ? 0.f : 180.f;

        FRotator NewRotation = GetActorRotation();
        NewRotation.Yaw = DesiredYaw;

        SetActorRotation(NewRotation); // ĳ���� ��ü ȸ��
    }
}

FGenericTeamId AEnemyCharacter::GetGenericTeamId() const
{
    return FGenericTeamId(TeamID);
}

void AEnemyCharacter::PlayHitReaction(const FVector& FromLocation)
{
    if (HitReactMontage && !IsPlayingRootMotion())
    {
        PlayAnimMontage(HitReactMontage);
    }
}

