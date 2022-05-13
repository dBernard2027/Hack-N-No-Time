// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillManagerComponent.h"
#include "SkillBase.h"
#include "ProjetTopDownCharacter.h"

// Sets default values for this component's properties
USkillManagerComponent::USkillManagerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


void USkillManagerComponent::OnSkillRequested(const int32 _skillIndex)
{
	if (_skillIndex >= 0 && _skillIndex < Skills.Num() && Skills[_skillIndex] != nullptr)
	{
		// Check if another skill is executing
		if (!IsASkillExecuting())
		{
			bool bSkillExecution = Skills[_skillIndex]->RequestExecution();
			//do whatever with the bool
		}
	}
}

// Called when the game starts
void USkillManagerComponent::BeginPlay()
{
	Super::BeginPlay();

	//Init skill manager ref on skills
	for (auto skill : Skills)
	{
		if (skill != nullptr)
			skill->SkillMgrOwner = this;
	}
}

bool USkillManagerComponent::IsASkillExecuting()
{
	for (auto skill : Skills)
	{
		if (skill != nullptr && skill->isExecuting == true)
			return true;
	}

	return false;
}


// Called every frame
void USkillManagerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (auto skill : Skills)
	{
		if (skill != nullptr)
		{
			skill->TickSkill(DeltaTime);
		}
	}
}

AProjetTopDownCharacter* USkillManagerComponent::GetOwnerCharacter()
{
	return Cast<AProjetTopDownCharacter>(GetOwner());
}

