// Fill out your copyright notice in the Description page of Project Settings.


#include "SwapBool.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"

EBTNodeResult::Type USwapBool::ExecuteTask(UBehaviorTreeComponent& Owner_Comp, uint8* Node_Memory)
{
	UBlackboardComponent* ownerBB = Owner_Comp.GetBlackboardComponent();
	ownerBB->SetValueAsBool(ValueToClear.SelectedKeyName, newValue);
	return EBTNodeResult::Type();
}
