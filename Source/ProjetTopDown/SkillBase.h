// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkillBase.generated.h"

/**
 * Base class for skills
 */
UCLASS(Blueprintable, BlueprintType, EditInLineNew)
class PROJETTOPDOWN_API USkillBase : public UObject
{
	GENERATED_BODY()

public:
	// Ref on skill manager owner
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class USkillManagerComponent* SkillMgrOwner = nullptr;


	//-- Skill Datas (can be done in a data only class)
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 range = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float cooldown = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float castTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float castCost = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float dmg = 10.0f;

	//... anything you want for all yours skills

	//-- 

	//-- Utils datas (execution, timers ...)
	bool isExecuting = false;

	float currentCooldownTimer = 0.0f;
	float currentCastTimer = -1.0f;
	
	//--

	virtual bool RequestExecution();

	virtual void TickSkill(float _deltaTime);

	//-- Detection triggers events (used by skill with detection mesh)	
	virtual void DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	virtual void DetectionMeshEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	//--

	//-- Projectile detection triggers event (used by skill with projectile)
	virtual void ProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	virtual void ProjectileEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	//--

	//-- BP Events (spawn sfx/vfx etc.)
	UFUNCTION(BlueprintImplementableEvent)
	void Event_OnExecuteBP();

	UFUNCTION(BlueprintImplementableEvent)
	void Event_OnEndExecutionBP();

	UFUNCTION(BlueprintImplementableEvent)
	void Event_TickSkillBP(float _deltaTime);

	UFUNCTION(BlueprintImplementableEvent)
	void Event_DetectionMeshBeginOverlapBP(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void Event_DetectionMeshEndOverlapBP(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent)
	void Event_ProjectileBeginOverlapBP(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void Event_ProjectileEndOverlapBP(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	//--

protected:
	virtual void Execute();

	virtual void EndExecution();
	
};
