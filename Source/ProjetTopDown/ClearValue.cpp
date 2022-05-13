// Fill out your copyright notice in the Description page of Project Settings.


#include "ClearValue.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"

EBTNodeResult::Type UClearValue::ExecuteTask(UBehaviorTreeComponent& Owner_Comp, uint8* Node_Memory)
{
	UBlackboardComponent* ownerBB = Owner_Comp.GetBlackboardComponent();
	ownerBB->ClearValue(ValueToClear.SelectedKeyName);
	return EBTNodeResult::Type();
}
