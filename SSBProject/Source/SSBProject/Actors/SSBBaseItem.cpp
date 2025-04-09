// Fill out your copyright notice in the Description page of Project Settings.


#include "SSBBaseItem.h"
#include "Components/SphereComponent.h"

// Sets default values
ASSBBaseItem::ASSBBaseItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	SetRootComponent(Scene);
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Collision->SetupAttachment(Scene);
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(Collision);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ASSBBaseItem::OnItemOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &ASSBBaseItem::OnItemEndOverlap);
}
void ASSBBaseItem::OnItemOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult)
{
	// OtherActor가 플레이어인지 확인 ("Player" 태그 활용)
	if (OtherActor && OtherActor->ActorHasTag("Player"))
	{
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap!!!")));
		// 아이템 사용 (획득) 로직 호출
		ActivateItem(OtherActor);
	}
}
void ASSBBaseItem::OnItemEndOverlap(
	UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
}
void ASSBBaseItem::ActivateItem(AActor* Activator)
{
	GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString::Printf(TEXT("Overlap!!")));
}
FName ASSBBaseItem::GetItemType() const
{
	return ItemType;
}
void ASSBBaseItem::DestroyItem()
{
	Destroy();
}

// Called when the game starts or when spawned
void ASSBBaseItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASSBBaseItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

