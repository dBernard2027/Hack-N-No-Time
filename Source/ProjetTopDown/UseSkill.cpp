// Fill out your copyright notice in the Description page of Project Settings.


#include "UseSkill.h"

#include "ProjetTopDownCharacter.h"
#include "EntityAiController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "GameFramework/Character.h"

EBTNodeResult::Type UUseSkill::ExecuteTask(UBehaviorTreeComponent& Owner_Comp, uint8* Node_Memory)
{
	UBlackboardComponent* ownerBB = Owner_Comp.GetBlackboardComponent();
	ACharacter* entityToChase = Cast<ACharacter>(ownerBB->GetValueAsObject(EntityActor.SelectedKeyName));

	AEntityAiController* const entityController = Cast<AEntityAiController>(Owner_Comp.GetAIOwner());
	AProjetTopDownCharacter* const entityCharacter = Cast<AProjetTopDownCharacter>(entityController->GetPawn());

	entityCharacter->OnSkillRequested(SpellIndex);

	return EBTNodeResult::Type();
}
