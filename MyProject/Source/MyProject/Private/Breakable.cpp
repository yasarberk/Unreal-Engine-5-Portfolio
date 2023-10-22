// Fill out your copyright notice in the Description page of Project Settings.


#include "Breakable.h"
#include "GeometryCollection/GeometryCollectionComponent.h"
#include "Treasure.h"
#include "Components/CapsuleComponent.h"


// Sets default values
ABreakable::ABreakable()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	GeometryCollection = CreateDefaultSubobject<UGeometryCollectionComponent>(TEXT("GeometryCollection"));
	SetRootComponent(GeometryCollection);
	GeometryCollection->SetGenerateOverlapEvents(true);
	GeometryCollection->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
	GeometryCollection->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Component"));
	CapsuleComponent->SetupAttachment(GetRootComponent());
	CapsuleComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CapsuleComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Block);
}

void ABreakable::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABreakable::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABreakable::GetHit_Implementation(const FVector& ImpactPoint)
{
	if (bBroken) return;
	bBroken = true;

	UWorld* World = GetWorld();
	if (World && (TreasureClasses.Num() > 0))
	{
		FVector Location = GetActorLocation();
		Location.Z += 75.f;

		int32 Selection = FMath::RandRange(0, TreasureClasses.Num() - 1);

		World->SpawnActor<ATreasure>(
			TreasureClasses[Selection],
			Location,
			GetActorRotation()
		 );
	}
}

