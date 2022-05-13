// Fill out your copyright notice in the Description page of Project Settings.


#include "SkillProjectile.h"
#include "SkillLinearProjectile.h"
#include "SkillManagerComponent.h"
#include "ProjetTopDownCharacter.h"

void USkillProjectile::Execute()
{
	if (SkillMgrOwner != nullptr)
	{
		ASkillLinearProjectile* projectile = nullptr;
		projectile = SkillMgrOwner->GetWorld()->SpawnActorDeferred<ASkillLinearProjectile>(projectileBP, SkillMgrOwner->GetOwnerCharacter()->GetTransform());

		if (projectile != nullptr)
		{
			projectile->Init(this, SkillMgrOwner->GetOwnerCharacter()->GetActorForwardVector(), projectileSpeed, range);
			projectile->FinishSpawning(SkillMgrOwner->GetOwnerCharacter()->GetTransform());
		}
	}

	Super::Execute();
}

void USkillProjectile::ProjectileBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Super::ProjectileBeginOverlap(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	//TODO damage logic here
}
