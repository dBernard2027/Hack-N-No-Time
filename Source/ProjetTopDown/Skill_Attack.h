// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillBase.h"
#include "Skill_Attack.generated.h"

/**
 * 
 */
UCLASS()
class PROJETTOPDOWN_API USkill_Attack : public USkillBase
{
	GENERATED_BODY()
protected:
	virtual void Execute() override;

public:
	virtual void DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 attackIndex = 0; //between 0 and 2 (not the same anim/hit detection/damage)

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ASkillCollisionDetection> firstAndSecondAttacksDetection;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ASkillCollisionDetection> thirdAttackDetection;
		
};
