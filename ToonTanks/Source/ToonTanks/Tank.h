// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

	void HandleDestruction();

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	APlayerController *GetTankPlayerController() const { return TankPlayerController; }

	bool bAlive = true;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	UPROPERTY(VisibleAnyWhere, Category="Components")
	class USpringArmComponent *SpringArm;
	UPROPERTY(VisibleAnyWhere, Category = "Components")
	class UCameraComponent *Camera;

	UPROPERTY(EditAnyWhere, Category="Movement")
	float Speed = 20.f;
	UPROPERTY(EditAnyWhere, Category="Movement")
	float TurnRate = 45.5;

	void Move(float value);
	void Turn(float value);

	APlayerController* TankPlayerController;
};
