// Fill out your copyright notice in the Description page of Project Settings.

#include "EntityAiController.h"
#include "ProjetTopDownCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"

#include "ChasePlayer.h"

EBTNodeResult::Type UChasePlayer::ExecuteTask(UBehaviorTreeComponent& Owner_Comp, uint8* Node_Memory)
{
	UBlackboardComponent* ownerBB = Owner_Comp.GetBlackboardComponent();
	ACharacter* entityToChase = Cast<ACharacter>(ownerBB->GetValueAsObject(EntityActor.SelectedKeyName));

	AEntityAiController* const entityController = Cast<AEntityAiController>(Owner_Comp.GetAIOwner());
	AProjetTopDownCharacter* const entityCharacter = Cast<AProjetTopDownCharacter>(entityController->GetPawn());

	//entityCharacter->UpdateWalkSpeed(ChaseSpeed);

	return EBTNodeResult::Type();
}