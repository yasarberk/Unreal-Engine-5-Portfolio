// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAnimInstance.h"
#include "MyCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UCharacterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	myCharacter = Cast<AMyCharacter>(TryGetPawnOwner());
	
	if (myCharacter)
	{
		myCharacterMovement=  myCharacter->GetCharacterMovement();
	}
	
}

void UCharacterAnimInstance::NativeUpdateAnimation(float deltaTime)
{
	Super::NativeUpdateAnimation(deltaTime);

	if (myCharacterMovement)
	{
		groundSpeed = UKismetMathLibrary::VSizeXY(myCharacterMovement->Velocity);
		isFalling = myCharacterMovement->IsFalling();
		CharacterState = myCharacter->GetCharacterState();
	}
}
