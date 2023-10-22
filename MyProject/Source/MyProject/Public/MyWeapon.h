// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyItem.h"
#include "MyWeapon.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AMyWeapon : public AMyItem
{
	GENERATED_BODY()

public:
	AMyWeapon();

	void Equip(USceneComponent* InParent, FName InSocketName, AActor* NewOwner, APawn* NewInstigator);

	void AttachMeshToSocket(USceneComponent* InParent, const FName& InSocketName);

protected:

	virtual void BeginPlay() override;

	virtual void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
	virtual void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) override;
	
	UFUNCTION()
	void OnBoxOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void CreateFields(const FVector& FieldLocation);

private:

	UPROPERTY(EditAnyWhere, category = "Weapon Properties")
	class USoundBase* EquipSound;

	UPROPERTY(EditAnyWhere, category = "Weapon Properties")
	class UBoxComponent* WeaponBox;

	UPROPERTY(VisibleAnyWhere)
	USceneComponent* BoxTraceStart;
	UPROPERTY(VisibleAnyWhere)
	USceneComponent* BoxTraceEnd;

	UPROPERTY(EditAnyWhere, category = "Weapon Properties")
	float Damage = 20.f;

public:

	FORCEINLINE UBoxComponent* GetWeaponBox() const { return WeaponBox; }

	TArray<AActor*> IgnoreActors;
};
