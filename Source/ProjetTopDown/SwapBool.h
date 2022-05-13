// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "SwapBool.generated.h"

/**
 * 
 */
UCLASS()
class PROJETTOPDOWN_API USwapBool : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		FBlackboardKeySelector ValueToClear;

	UPROPERTY(EditAnywhere)
		bool newValue;

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& Owner_Comp, uint8* Node_Memory);
};
