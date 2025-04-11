#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GenericTeamAgentInterface.h"
#include "GameplayAbilitySpec.h"
#include "EnemyCharacter.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;
class UEnemyCombatComponent;
/*
* 스켈레탈 메시, 무브먼트, 스킬 트리거
*/
UCLASS()
class SSBPROJECT_API AEnemyCharacter : public ACharacter, public IGenericTeamAgentInterface
{
	GENERATED_BODY()

public:
	AEnemyCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	UEnemyCombatComponent* CombatComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystem")
	UAbilitySystemComponent* AbilitySystem;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Combat")
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Team", meta = (ClampMin = "0", ClampMax = "255"))
	uint8 TeamID = 1;

	UFUNCTION(BlueprintCallable)
	void PlayHitReaction(const FVector& FromLocation);

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual FGenericTeamId GetGenericTeamId() const override;
};
