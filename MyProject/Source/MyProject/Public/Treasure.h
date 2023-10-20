// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyItem.h"
#include "Treasure.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API ATreasure : public AMyItem
{
	GENERATED_BODY()

protected:

	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:

	UPROPERTY(EditAnyWhere, Category = "Sounds")
	USoundBase* PickupSound;

	UPROPERTY(EditAnyWhere, Category = "Treasure Properties")
	int32 Gold;

	
};
