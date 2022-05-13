// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Entity.generated.h"

UCLASS()
class PROJETTOPDOWN_API AEntity : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEntity();





protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float HealthPoint = 100.f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float MaxHealthPoint = 100.f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float ManaPoint = 250.f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		float MaxManaPoint = 250.f;

	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		bool IsAlive = true;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void Heal(int _value, bool _overload = false);

	UFUNCTION(BlueprintCallable)
		void InflictDmg(int _value, bool _overload = false);

	UFUNCTION(BlueprintCallable)
		bool ConsumeMana(int _value, bool _overload = false);

	UFUNCTION(BlueprintCallable)
		bool RestoreMana(int _value, bool _overload = false);

	UFUNCTION(BlueprintImplementableEvent)
		void Event_OnDeath();

};
