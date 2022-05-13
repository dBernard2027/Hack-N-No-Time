// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill_Attack.h"
#include "SkillCollisionDetection.h"
#include "SkillManagerComponent.h"
#include "ProjetTopDownCharacter.h"

void USkill_Attack::Execute()
{
	//-- 3 different attacks : 1st and 2nd deal regular damage, 3rd deals final damage (each one has an anim (played in BP))
	if (attackIndex == 3)
		attackIndex = 1;
	else
		attackIndex++;

	if (SkillMgrOwner != nullptr)
	{
		ASkillCollisionDetection* detection = nullptr;
		if (attackIndex == 3)
			detection = SkillMgrOwner->GetWorld()->SpawnActorDeferred<ASkillCollisionDetection>(thirdAttackDetection, SkillMgrOwner->GetOwnerCharacter()->GetTransform());
		else
			detection = SkillMgrOwner->GetWorld()->SpawnActorDeferred<ASkillCollisionDetection>(firstAndSecondAttacksDetection, SkillMgrOwner->GetOwnerCharacter()->GetTransform());

		if (detection != nullptr)
		{
			detection->Init(this);
			detection->FinishSpawning(SkillMgrOwner->GetOwnerCharacter()->GetTransform());
		}
	}

	Super::Execute();
}

void USkill_Attack::DetectionMeshBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Super::DetectionMeshBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	//Todo : DAMAGE logic here
}
