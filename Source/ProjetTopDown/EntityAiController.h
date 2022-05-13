// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Components/ActorComponent.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISenseConfig_Sight.h"
#include "EntityAiController.generated.h"


UCLASS()
class PROJETTOPDOWN_API AEntityAiController : public AAIController
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	AEntityAiController();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "AI Sight Component")
		UAISenseConfig_Sight* EntitySightComponent;

	UPROPERTY(EditAnywhere, Category = "Behavior Tree")
		UBehaviorTree* Entity_BT;
	UPROPERTY(EditAnywhere, Category = "Behavior Tree")
		FName EntityToChase = "EntityToChase";
	UPROPERTY(EditAnywhere, Category = "Behavior Tree")
		FName PatrolLocation = "PatrolLocation";
	UPROPERTY(EditAnywhere, Category = "Behavior Tree")
		FName EntityActor = "EntityActor";
	UPROPERTY(EditAnywhere, Category = "Behavior Tree")
		FName HasLineOfSight = "HasLineOfSight";
	UPROPERTY(EditAnywhere, Category = "Behavior Tree")
		FName IsChasingEnemy = "IsChasingEnemy";
	UPROPERTY(EditAnywhere, Category = "Behavior Tree")
		FName LastSeen = "LastSeen";
	UPROPERTY(EditAnywhere, Category = "Behavior Tree")
		FName RemainingSearch = "RemainingSearch";


	UFUNCTION()
		void OnPerceptionUpdate(AActor* actor, FAIStimulus stimulus);
protected:
	virtual void OnPossess(APawn* InPawn) override;

public:
};
