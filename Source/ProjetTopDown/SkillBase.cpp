// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillBase.h"
#include "SkillManagerComponent.h"
#include "ProjetTopDownCharacter.h"



bool USkillBase::RequestExecution()
{
	// test cooldown
	if (currentCooldownTimer <= 0.0f && Cast<AEntity>(SkillMgrOwner->GetOwnerCharacter())->ConsumeMana(castCost))
	{
		//Test cast Time
		if (castTime <= 0.0f )
			Execute();
		else
		{
			isExecuting = true;
			currentCastTimer = castTime;
		}

		return true;
	}

	return false;
}

void USkillBase::TickSkill(float _deltaTime)
{
	//-- Update Cooldown
	if (currentCooldownTimer > 0.0f)
		currentCooldownTimer -= _deltaTime;

	if (currentCooldownTimer < 0.0f)
	{
		currentCooldownTimer = 0.0f;
		//todo signal this to UI ? (feedback)
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("SkillBase:: Cooldown Ready !")));
	}

	//-- Update cast time
	if (currentCastTimer > 0.0f)
	{
		currentCastTimer -= _deltaTime;

		if (currentCastTimer <= 0.0f)
			Execute();
	}

	Event_TickSkillBP(_deltaTime);
}

void USkillBase::DetectionMeshBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//override to implement event if needed
	Event_DetectionMeshBeginOverlapBP(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("SkillBase:: BeginOverlap CPP")));
}

void USkillBase::DetectionMeshEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	//override to implement event if needed
	Event_DetectionMeshEndOverlapBP(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("SkillBase:: EndOverlap CPP")));
}

void USkillBase::ProjectileBeginOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	//override to implement event if needed
	Event_ProjectileBeginOverlapBP(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("SkillBase:: BeginOverlap CPP")));
}

void USkillBase::ProjectileEndOverlap(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	//override to implement event if needed
	Event_ProjectileEndOverlapBP(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, FString::Printf(TEXT("SkillBase:: EndOverlap CPP")));
}

void USkillBase::Execute()
{
	isExecuting = true;
	currentCastTimer = -1.0f;
	if (AEntity* entity = Cast<AEntity>(SkillMgrOwner->GetOwnerCharacter()))
	{
		
	}

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, FString::Printf(TEXT("SkillBase:: Execute")));

	//...do skill stuff here
	Event_OnExecuteBP();

	EndExecution();
}

void USkillBase::EndExecution()
{
	currentCooldownTimer = cooldown;

	Event_OnEndExecutionBP();

	isExecuting = false;
}