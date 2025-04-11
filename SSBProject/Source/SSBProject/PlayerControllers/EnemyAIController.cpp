#include "EnemyAIController.h" 
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "EnemyCombatComponent.h"
#include "EnemyCharacter.h"
#include "GenericTeamAgentInterface.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"

AEnemyAIController::AEnemyAIController()
{
    PrimaryActorTick.bCanEverTick = true;
}

void AEnemyAIController::BeginPlay()
{
    Super::BeginPlay();

    // 추후 행동 시작 시 초기화 등 추가 가능
}

void AEnemyAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

    APawn* ControlledPawn = GetPawn();
    APawn* TargetPlayer = GetTargetPlayer();

    if (!ControlledPawn || !TargetPlayer) return;

    FVector PlayerLocation = TargetPlayer->GetActorLocation();
    FVector MyLocation = ControlledPawn->GetActorLocation();

    DistanceX = MyLocation.Y - PlayerLocation.Y;
    MoveDir = FMath::Sign(DistanceX);

    FVector ForwardVector = ControlledPawn->GetActorForwardVector();
    FVector InputDirection = ForwardVector * MoveDir;
    //FVector InputDirection = FVector(MoveDir, 0.f, 0.f);

    AEnemyCharacter* Enemy = Cast<AEnemyCharacter>(ControlledPawn);
    if (Enemy && Enemy->CombatComponent)
    {
        if (FMath::Abs(DistanceX) > 100.f && !Enemy->CombatComponent->bIsAttacking)
        {
            ControlledPawn->AddMovementInput(InputDirection);
        }
        else
        {
            Enemy->CombatComponent->TryAttack();
        }
        /*if (FMath::Abs(DistanceX) < 200.f && !Enemy->CombatComponent->bIsAttacking)
        {
            Enemy->CombatComponent->TryAttack();
        }*/
    }

    /*ACharacter* LocalCharacter = Cast<ACharacter>(ControlledPawn);
    if (LocalCharacter)
    {
        float VerticalDifference = PlayerLocation.Z - MyLocation.Z;

        if (VerticalDifference > 200.f && LocalCharacter->GetCharacterMovement()->IsMovingOnGround())
        {
            LocalCharacter->Jump();
        }
    }*/
}

APawn* AEnemyAIController::GetTargetPlayer() const
{
    TArray<AActor*> AllActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawn::StaticClass(), AllActors);

    for (AActor* Actor : AllActors)
    {
        // 자기 자신 제외
        if (Actor == GetPawn()) continue;
        
        // 첫 번째로 찾은 플레이어 캐릭터 반환
        if (Actor->IsA(ACharacter::StaticClass()))
        {
            return Cast<APawn>(Actor);
        }
    }

    return nullptr;
}
//자체 팀 아이디로 구분 타겟팅이나 플레이어 캐릭터에 없어서 안쫓아오는 이유로 일단 주석처리
//APawn* AEnemyAIController::GetTargetPlayer() const
//{
//    TArray<AActor*> AllActors;
//    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawn::StaticClass(), AllActors);
//
//    for (AActor* Actor : AllActors)
//    {
//        // 자기 자신 제외
//        if (Actor == GetPawn()) continue;
//
//        const IGenericTeamAgentInterface* OtherTeamAgent = Cast<IGenericTeamAgentInterface>(Actor);
//        if (OtherTeamAgent)
//        {
//            if (GetTeamAttitudeTowards(*Actor) == ETeamAttitude::Hostile)
//            {
//                // 최초로 찾은 적 반환
//                // 여기서 공격 모션이 끝나면 계속 쫓아가는게 아니라 다시 적 반환 예정
//                return Cast<APawn>(Actor);
//            }
//        }
//    }
//    // 적 없음
//    return nullptr;
//}

//ETeamAttitude::Type AEnemyAIController::GetTeamAttitudeTowards(const AActor& Other) const
//{
//    // 비교 기준을 Controller가 아닌 "내 Pawn"에서 가져오도록 수정
//    const APawn* MyPawn = GetPawn();
//    const IGenericTeamAgentInterface* MyTeamAgent = Cast<IGenericTeamAgentInterface>(MyPawn);
//    const IGenericTeamAgentInterface* OtherTeamAgent = Cast<IGenericTeamAgentInterface>(&Other);
//
//    if (MyTeamAgent && OtherTeamAgent)
//    {
//        return (MyTeamAgent->GetGenericTeamId() == OtherTeamAgent->GetGenericTeamId())
//            ? ETeamAttitude::Friendly
//            : ETeamAttitude::Hostile;
//    }
//
//    return ETeamAttitude::Neutral;
//}