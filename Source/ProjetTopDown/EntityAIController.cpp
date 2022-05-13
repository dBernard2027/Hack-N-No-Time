// Fill out your copyright notice in the Description page of Project Settings.


#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "EntityAIController.h"

#include "Faction.h"
#include "ProjetTopDownCharacter.h"

AEntityAiController::AEntityAiController()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AI Perception"));
	EntitySightComponent = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("AI Sight"));

	EntitySightComponent->DetectionByAffiliation.bDetectNeutrals = true;
	EntitySightComponent->DetectionByAffiliation.bDetectFriendlies = true;
	EntitySightComponent->DetectionByAffiliation.bDetectEnemies = true;

	PerceptionComponent->ConfigureSense(*EntitySightComponent);
}

void AEntityAiController::BeginPlay()
{
	Super::BeginPlay();
	GetAIPerceptionComponent()->OnTargetPerceptionUpdated.AddUniqueDynamic(this, &AEntityAiController::OnPerceptionUpdate);
	GetBlackboardComponent()->SetValueAsVector(FName("StartPosition"), GetPawn()->GetActorLocation());
}

void AEntityAiController::OnPerceptionUpdate(AActor* actor, FAIStimulus stimulus)
{
	UFaction* faction = actor->FindComponentByClass<UFaction>();
	if (faction && !actor->IsUnreachable())
	{
		if (GetPawn()->FindComponentByClass<UFaction>()->Enemies.Contains(faction->CurrentFaction) && stimulus.WasSuccessfullySensed())
		{
			GetBlackboardComponent()->SetValueAsBool(HasLineOfSight, true);
			GetBlackboardComponent()->SetValueAsBool(IsChasingEnemy, true);
			GetBlackboardComponent()->SetValueAsObject(EntityToChase, actor);
		}
		else if (actor == GetBlackboardComponent()->GetValueAsObject(EntityToChase))
		{
			GetBlackboardComponent()->SetValueAsBool(HasLineOfSight, false);
			GetBlackboardComponent()->SetValueAsVector(LastSeen, actor->GetActorLocation());
			GetBlackboardComponent()->ClearValue(EntityToChase);
		}
	}
}

void AEntityAiController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	RunBehaviorTree(Entity_BT);
	SetPawn(InPawn);
	AProjetTopDownCharacter* entity = Cast<AProjetTopDownCharacter>(InPawn);
}
