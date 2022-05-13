// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "UseSkill.generated.h"

/**
 * 
 */
UCLASS()
class PROJETTOPDOWN_API UUseSkill : public UBTTaskNode
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere)
		FBlackboardKeySelector EntityActor;

	UPROPERTY(EditAnywhere)
		int32 SpellIndex;

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Owner_Comp, uint8* Node_Memory);
	
};
