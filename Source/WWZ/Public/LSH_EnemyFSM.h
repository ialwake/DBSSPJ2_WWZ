// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LSH_EnemyFSM.generated.h"

//사용할 상태 정의
UENUM(BlueprintType)
enum class EEnemyState :uint8
{
	Idle,
	Move,
	Attack,
	Damage,
	Die,
};


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WWZ_API ULSH_EnemyFSM : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULSH_EnemyFSM();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "FSM")
	EEnemyState mState = EEnemyState::Idle;

	void IdleState();
	void MoveState();
	void AttackState();
	void DamageState();
	void DieState();

	UPROPERTY(EditDefaultsOnly, Category = "FSM")
	float idleDelayTime = 2;
	float currentTime = 0;

	UPROPERTY(VisibleAnywhere, Category = "FSM")
	class AWWZCharacter* target;

	UPROPERTY()
	class ALSH_BaseZom* me;

	UPROPERTY(EditAnywhere, Category = "FSM")
	float attackRange = 150.0f;

	UPROPERTY(EditAnywhere, Category = "FSM")
	float attackDelayTime = 2.0f;

	void OnDamageProcess();

	//HP
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "FSM")
	int32 hp = 3;
	//피격대기시간
	UPROPERTY(EditAnywhere, Category = "FSM")
	float damageDelayTime = 2.0f;
	//아래로 사라지는 속도
	UPROPERTY(EditAnywhere, Category = "FSM")
	float dieSpeed = 50.0f;
};
