#include "EnemyCharacter.h"
#include "EnemyCombatComponent.h"
#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"
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

    APawn* Target = Cast<APawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
    if (!Target) return;

    FVector ToTarget = Target->GetActorLocation() - GetActorLocation();
    ToTarget.Z = 0.f;

    if (ToTarget.SizeSquared() > 25.f)
    {
        FRotator TargetRotation = ToTarget.Rotation();
        float AngleDiff = FMath::Abs(FMath::FindDeltaAngleDegrees(GetActorRotation().Yaw, TargetRotation.Yaw));

        // 부드럽게 회전
        FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TargetRotation, DeltaTime, 10.f);
        SetActorRotation(NewRotation);

        // 회전이 덜 끝났으면 이동 금지 신호
        bRotationFinished = (AngleDiff < 10.f);
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

