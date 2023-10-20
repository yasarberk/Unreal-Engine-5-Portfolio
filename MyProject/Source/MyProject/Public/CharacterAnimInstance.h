// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Characters/CharacterTypes.h"
#include "CharacterAnimInstance.generated.h"
/**
 * 
 */
UCLASS()
class MYPROJECT_API UCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float deltaTime) override;

	UPROPERTY(BlueprintReadOnly)
	class AMyCharacter* myCharacter;
	
	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	class UCharacterMovementComponent* myCharacterMovement;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	float groundSpeed;

	UPROPERTY(BlueprintReadOnly, Category = "Movement")
	bool isFalling;

	UPROPERTY(BlueprintReadOnly, Category = "Movement | Character State")
	ECharacterState CharacterState;
};
