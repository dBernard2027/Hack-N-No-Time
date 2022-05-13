// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Entity.h"
#include "Faction.h"
#include "GameFramework/Character.h"
#include "ProjetTopDownCharacter.generated.h"

UCLASS(Blueprintable)
class AProjetTopDownCharacter : public AEntity
{
	GENERATED_BODY()

public:
	AProjetTopDownCharacter();

	// Called every frame.
	virtual void Tick(float DeltaSeconds) override;

	/** Returns TopDownCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetTopDownCameraComponent() const { return TopDownCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

private:
	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	//CORRECTION
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector MovementVectorThisFrame = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UFaction* Faction;



private:
	// Orient Character to mouse ONLY if he is controlled by a APlayerController (=only on player pawn)
	void OrientCharacterToMouse();

protected:
	// Setup Input bindings
	virtual void SetupPlayerInputComponent(class UInputComponent* _PlayerInputComponent) override;

	//-- Move Axis callbacks
	void OnMoveForwardAxis(const float _value);
	void OnMoveRightAxis(const float _value);
	//--

	//Character Data
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MoveSpeed = 10000;



	//-- Skills
protected:
	//-- Skills inputs callbacks
	void OnSkill0Input();
	void OnSkill1Input();
	void OnSkill2Input();

	//-- Skill manager
	UPROPERTY(EditAnywhere)
	class USkillManagerComponent* SkillManager;

public:
	UFUNCTION(BlueprintCallable)
	void OnSkillRequested(const int32 _skillIndex);

	UFUNCTION(BlueprintCallable)
	void UpdateWalkSpeed(float _newWalkSpeed);
};

