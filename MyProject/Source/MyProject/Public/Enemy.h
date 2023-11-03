// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "HitInterface.h"
#include "Characters/CharacterTypes.h"
#include "Enemy.generated.h"

UCLASS()
class MYPROJECT_API AEnemy : public ABaseCharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CheckPatrolTarget();

	void CheckCombatTarget();

	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	virtual void Destroyed() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Die() override;
	bool InTargetRange(AActor* Target, double Radius);

	void MoveToTarget(AActor* Target);

	AActor* ChoosePatrolTarget();

	virtual void Attack() override;
	virtual void PlayAttackMontage() override;
	virtual bool CanAttack() override;
	virtual void HandleDamage(float DamageAmount) override;

	UPROPERTY(BlueprintReadOnly)
	EDeathPose DeathPose;

	UPROPERTY(BlueprintReadOnly)
	EEnemyState EnemyState = EEnemyState::EES_Patrolling;

	UFUNCTION()
	void PawnSeen(APawn* SeenPawn);

private:

	/*
	Components
	*/

	class UPawnSensingComponent* PawnSensingComponent;
	
	UPROPERTY(VisibleAnyWhere)
	class UHealthBarComponent* HealthBarWidget;

	UPROPERTY(EditAnyWhere)
	TSubclassOf<class AMyWeapon> WeaponClass;

	UPROPERTY()
	AActor* CombatTarget;

	UPROPERTY(EditAnyWhere)
	double CombatRadius = 500.f;

	UPROPERTY(EditAnyWhere)
	double AttackRadius = 150.f;

	/*
	* Navigation
	*/

	UPROPERTY()
	class AAIController* EnemyController;

	//Current patrol target
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	AActor* PatrolTarget;
	
	UPROPERTY(EditInstanceOnly, Category = "AI Navigation")
	TArray<AActor*> PatrolTargets;

	UPROPERTY(EditAnyWhere)
	double PatrolRadius = 200.f;

	FTimerHandle PatrolTimer;
	void PatrolTimerFinished();

	UPROPERTY(EditAnyWhere, Category = "AI Navigation")
	float WaitMin = 5.f;
	UPROPERTY(EditAnyWhere, Category = "AI Navigation")
	float WaitMax = 10.f;

	// AI Behavior
	void HideHealthBar();
	void ShowHealthBar();
	void LoseInterest();
	void StartPatrolling();
	void ChaseTarget();
	void ClearPatrolTimer();
	bool IsOutsideCombatRadius();
	bool IsOutsideAttackRadius();
	bool IsInsideAttackRadius();
	bool IsChasing();
	bool IsAttacking();
	bool IsDead();
	bool IsEngaged();


	// Combat
	void StartAttackTimer();
	void ClearAttackTimer();

	FTimerHandle AttackTimer;
	
	UPROPERTY(EditAnyWhere, Category = "Combat")
	float AttackMin = 0.5f;
	UPROPERTY(EditAnyWhere, Category = "Combat")
	float AttackMax = 1.f;

	UPROPERTY(EditAnyWhere, Category = "Combat")
	float PatrollingSpeed = 125.f;
	UPROPERTY(EditAnyWhere, Category = "Combat")
	float ChasingSpeed = 300.f;
};
