// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HitInterface.h"
#include "Breakable.generated.h"

class UGeometryCollectionComponent;

UCLASS()
class MYPROJECT_API ABreakable : public AActor, public IHitInterface
{
	GENERATED_BODY()
	
public:	
	ABreakable();
	
	virtual void Tick(float DeltaTime) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;


protected:
	
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
	UGeometryCollectionComponent* GeometryCollection;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite)
	class UCapsuleComponent* CapsuleComponent;

private:

	UPROPERTY(EditAnyWhere, Category = "Breakable Properties")
	TArray<TSubclassOf<class ATreasure>> TreasureClasses;
};
