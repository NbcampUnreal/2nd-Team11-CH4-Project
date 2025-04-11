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

    // 향후 필요한 초기화 가능
}

void AEnemyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    FVector Velocity = GetVelocity();

    if (FMath::Abs(Velocity.X) > 5.f) // 거의 정지 상태가 아닐 때
    {
        float DesiredYaw = Velocity.X > 0 ? 0.f : 180.f;

        FRotator NewRotation = GetActorRotation();
        NewRotation.Yaw = DesiredYaw;

        SetActorRotation(NewRotation); // 캐릭터 전체 회전
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

