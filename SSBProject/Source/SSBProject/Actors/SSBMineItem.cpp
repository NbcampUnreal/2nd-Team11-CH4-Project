// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBMineItem.h"
#include "Components/SphereComponent.h"

ASSBMineItem::ASSBMineItem()
{
	ExplosionDelay = 0.1f;
	ExplosionRadius = 300.0f;
	ExplosionDamage = 30.0f;
	ItemType = "Mine";

	ExplosionCollision = CreateDefaultSubobject<USphereComponent>(TEXT("ExplosionCollision"));
	ExplosionCollision->InitSphereRadius(ExplosionRadius);
	ExplosionCollision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	ExplosionCollision->SetupAttachment(Scene);
}
void ASSBMineItem::ActivateItem(AActor* Activator)
{
	GetWorld()->GetTimerManager().SetTimer(ExplosionTimerHandle, this, &ASSBMineItem::Explode, ExplosionDelay);
}
void ASSBMineItem::Explode()
{
    TArray<AActor*> OverlappingActors;
    ExplosionCollision->GetOverlappingActors(OverlappingActors);

    for (AActor* Actor : OverlappingActors)
    {
        if (Actor && Actor->ActorHasTag("Player"))
        {
            OnMineTriggered(Actor);
        }
    }

    DestroyItem();
}