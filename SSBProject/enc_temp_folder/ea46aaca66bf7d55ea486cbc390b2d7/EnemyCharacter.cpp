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

    //FVector Velocity = GetVelocity();

    //if (FMath::Abs(Velocity.Y) > 5.f) // 거의 정지 상태가 아닐 때
    //{
    //    float DesiredYaw = Velocity.Y > 0 ? 0.f : 180.f;

    //    FRotator NewRotation = GetActorRotation();
    //    NewRotation.Yaw = DesiredYaw;

    //    SetActorRotation(NewRotation); // 캐릭터 전체 회전
    //}

    APawn* Target = Cast<APawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)); // 또는 다른 방식으로 타겟 획득
    if (!Target) return;

    FVector ToTarget = Target->GetActorLocation() - GetActorLocation();
    ToTarget.Z = 0.f; // 수직 방향 제거

    if (ToTarget.SizeSquared() > 25.f) // 너무 가까우면 회전하지 않음
    {
        FRotator TargetRotation = ToTarget.Rotation();
        SetActorRotation(TargetRotation);
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

