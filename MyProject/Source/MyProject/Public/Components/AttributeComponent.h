// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AttributeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MYPROJECT_API UAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UAttributeComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void ReceiveDamage(float Damage);
	float GetHealthPercent();
	bool IsAlive();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;	
		
private:
	
	//Current Health
	UPROPERTY(EditAnyWhere, Category = "Actor Attributes")
	float Health;

	UPROPERTY(EditAnyWhere, Category = "Actor Attributes")
	float MaxHealth;
};
