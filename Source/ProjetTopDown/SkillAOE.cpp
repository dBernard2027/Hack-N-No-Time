// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillAOE.h"
#include "SkillCollisionDetection.h"
#include "SkillManagerComponent.h"
#include "ProjetTopDownCharacter.h"
#include "Classes//Engine/EngineTypes.h"
#include "GameFramework/Actor.h"

void USkillAOE::Execute()
{
	isExecuting = true;
	currentCastTimer = -1.0f;

	if (SkillMgrOwner != nullptr)
	{
		ASkillCollisionDetection* detection = SkillMgrOwner->GetWorld()->SpawnActorDeferred<ASkillCollisionDetection>(collisionDetection, SkillMgrOwner->GetOwnerCharacter()->GetTransform());

		if (detection != nullptr)
		{
			detection->Init(this);
			detection->FinishSpawning(SkillMgrOwner->GetOwnerCharacter()->GetTransform());
		}
	}

	Event_OnExecuteBP();

	FTimerHandle ExecuteTimerHandle;
	SkillMgrOwner->GetOwnerCharacter()->GetWorldTimerManager().SetTimer(ExecuteTimerHandle, this, &USkillAOE::ExecuteHandle, 1.0f); //1.0 = a peu pres le temps que met l'anim	

	Super::Execute();
}

void USkillAOE::ExecuteHandle()
{
	EndExecution();
}

void USkillAOE::DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Super::DetectionMeshBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	//TODO : damage logic here
}
