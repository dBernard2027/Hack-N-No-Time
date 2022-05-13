// Fill out your copyright notice in the Description page of Project Settings.


#include "Entity.h"

// Sets default values
AEntity::AEntity()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEntity::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEntity::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEntity::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEntity::Heal(int _value, bool _overload)
{
	if ((HealthPoint+_value<MaxHealthPoint || _overload) && _value > 0)
	{
		HealthPoint += _value;
		if (!IsAlive && HealthPoint > 0)
		{
			IsAlive = true;
		}
	}
	else if (_value <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("HealthSystem-Heal: Value < 0"));
	}
}

void AEntity::InflictDmg(int _value, bool _overload)
{
	if (_value > 0)
	{
		HealthPoint -= _value;
		if (IsAlive && HealthPoint <= 0)
		{
			IsAlive = false;
			Event_OnDeath();
		}
	}
	else if (_value <= 0)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("HealthSystem-Heal: Value < 0"));
	}
}

bool AEntity::ConsumeMana(int _value, bool _overload)
{
	if ((ManaPoint - _value > 0 || _overload) && _value >= 0)
	{
		ManaPoint -= _value;
		return true;
	}
	else if (_value < 0)
	{
		return false;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("HealthSystem-Heal: Value < 0"));
	}
	return false;
}

bool AEntity::RestoreMana(int _value, bool _overload)
{
	if ((ManaPoint + _value <  MaxManaPoint || _overload) && _value >= 0)
	{
		ManaPoint -= _value;
		return true;
	}
	else if (ManaPoint + _value < MaxManaPoint)
	{
		ManaPoint = MaxManaPoint;
		return true;
	}
	else if (_value < 0)
	{
		return false;
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("HealthSystem-Heal: Value < 0"));
	}
	return false;
}

