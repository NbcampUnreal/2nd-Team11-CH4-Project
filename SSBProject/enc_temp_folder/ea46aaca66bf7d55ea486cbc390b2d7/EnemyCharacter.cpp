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

    // ���� �ʿ��� �ʱ�ȭ ����
}

void AEnemyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    //FVector Velocity = GetVelocity();

    //if (FMath::Abs(Velocity.Y) > 5.f) // ���� ���� ���°� �ƴ� ��
    //{
    //    float DesiredYaw = Velocity.Y > 0 ? 0.f : 180.f;

    //    FRotator NewRotation = GetActorRotation();
    //    NewRotation.Yaw = DesiredYaw;

    //    SetActorRotation(NewRotation); // ĳ���� ��ü ȸ��
    //}

    APawn* Target = Cast<APawn>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)); // �Ǵ� �ٸ� ������� Ÿ�� ȹ��
    if (!Target) return;

    FVector ToTarget = Target->GetActorLocation() - GetActorLocation();
    ToTarget.Z = 0.f; // ���� ���� ����

    if (ToTarget.SizeSquared() > 25.f) // �ʹ� ������ ȸ������ ����
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

