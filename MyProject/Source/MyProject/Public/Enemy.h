// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HitInterface.h"
#include "Characters/CharacterTypes.h"
#include "Enemy.generated.h"

class UAnimMontage;

UCLASS()
class MYPROJECT_API AEnemy : public ACharacter, public IHitInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

	void DirectionalHitReact(const FVector& ImpactPoint);

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void Die();

	//Animation Montages
	void PlayHitReactMontage(const FName& SectionName);

	UPROPERTY(BlueprintReadOnly)
	EDeathPose DeathPose = EDeathPose::EDP_Alive;

private:

	//Animation Montages
	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* HitReactMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
	UAnimMontage* DeathMontage;

	UPROPERTY(EditAnyWhere, Category = "Sounds")
	USoundBase* HitSound;

	UPROPERTY(EditAnyWhere, Category = "Visual Effects")
	UParticleSystem* HitParticles;
	
	UPROPERTY(VisibleAnyWhere)
	class UAttributeComponent* Attributes;
	
	UPROPERTY(VisibleAnyWhere)
	class UHealthBarComponent* HealthBarWidget;

	UPROPERTY()
	AActor* CombatTarget;

	UPROPERTY(EditAnyWhere)
	double CombatRadius = 500.f;

};
