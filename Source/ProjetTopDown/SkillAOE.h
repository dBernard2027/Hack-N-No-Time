// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillBase.h"
#include "SkillAOE.generated.h"

/**
 * 
 */
UCLASS()
class PROJETTOPDOWN_API USkillAOE : public USkillBase
{
	GENERATED_BODY()
protected:
	virtual void Execute() override;

	void ExecuteHandle();

public:
	virtual void DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) override;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ASkillCollisionDetection> collisionDetection;
};
