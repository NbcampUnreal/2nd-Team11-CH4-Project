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

    // ���� �ൿ ���� �� �ʱ�ȭ �� �߰� ����
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
        // �ڱ� �ڽ� ����
        if (Actor == GetPawn()) continue;
        
        // ù ��°�� ã�� �÷��̾� ĳ���� ��ȯ
        if (Actor->IsA(ACharacter::StaticClass()))
        {
            return Cast<APawn>(Actor);
        }
    }

    return nullptr;
}
//��ü �� ���̵�� ���� Ÿ�����̳� �÷��̾� ĳ���Ϳ� ��� ���Ѿƿ��� ������ �ϴ� �ּ�ó��
//APawn* AEnemyAIController::GetTargetPlayer() const
//{
//    TArray<AActor*> AllActors;
//    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawn::StaticClass(), AllActors);
//
//    for (AActor* Actor : AllActors)
//    {
//        // �ڱ� �ڽ� ����
//        if (Actor == GetPawn()) continue;
//
//        const IGenericTeamAgentInterface* OtherTeamAgent = Cast<IGenericTeamAgentInterface>(Actor);
//        if (OtherTeamAgent)
//        {
//            if (GetTeamAttitudeTowards(*Actor) == ETeamAttitude::Hostile)
//            {
//                // ���ʷ� ã�� �� ��ȯ
//                // ���⼭ ���� ����� ������ ��� �Ѿư��°� �ƴ϶� �ٽ� �� ��ȯ ����
//                return Cast<APawn>(Actor);
//            }
//        }
//    }
//    // �� ����
//    return nullptr;
//}

//ETeamAttitude::Type AEnemyAIController::GetTeamAttitudeTowards(const AActor& Other) const
//{
//    // �� ������ Controller�� �ƴ� "�� Pawn"���� ���������� ����
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