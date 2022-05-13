// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SkillBase.h"
#include "SkillProjectile.generated.h"

/**
 * 
 */
UCLASS()
class PROJETTOPDOWN_API USkillProjectile : public USkillBase
{
	GENERATED_BODY()
protected:
	virtual void Execute() override;

public:
	virtual void ProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float projectileSpeed = 2500.0f;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ASkillLinearProjectile> projectileBP;
};
