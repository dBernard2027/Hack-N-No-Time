// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ProjetTopDownCharacter.h"

#include "UObject/ConstructorHelpers.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/SpringArmComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Materials/Material.h"
#include "Engine/World.h"

#include "Components/InputComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "SkillManagerComponent.h"

AProjetTopDownCharacter::AProjetTopDownCharacter()
{
	Faction = CreateDefaultSubobject<UFaction>(TEXT("Faction Component"));

	// Set size for player capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// Don't rotate character to camera direction
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	//- CORRECTION
	GetCharacterMovement()->bOrientRotationToMovement = false; //Do not Rotate character to moving direction
	//-
	GetCharacterMovement()->RotationRate = FRotator(0.f, 640.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	// Create a camera boom...
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->SetUsingAbsoluteRotation(true); // Don't want arm to rotate when character does
	CameraBoom->TargetArmLength = 800.f;
	CameraBoom->SetRelativeRotation(FRotator(-60.f, 0.f, 0.f));
	CameraBoom->bDoCollisionTest = false; // Don't want to pull camera in when it collides with level

	// Create a camera...
	TopDownCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("TopDownCamera"));
	TopDownCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	TopDownCameraComponent->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Activate ticking in order to update the cursor every frame.
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

	//-- Skill manager
	SkillManager = CreateDefaultSubobject<USkillManagerComponent>("SkillManager");
}

void AProjetTopDownCharacter::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);

	// Movement
	if (!MovementVectorThisFrame.IsNearlyZero() && GetController() != nullptr)
	{
		MovementVectorThisFrame.Normalize(); //normalize inputs (to avoid diagonal moves to go faster)

		FVector vDestination = GetActorLocation() + (MovementVectorThisFrame * MoveSpeed * DeltaSeconds);

		//vDestination on navmesh
		vDestination = UNavigationSystemV1::GetNavigationSystem(GetWorld())->ProjectPointToNavigation(GetWorld(), vDestination);

		UAIBlueprintHelperLibrary::SimpleMoveToLocation(GetController(), vDestination);
	}

	// Orient Character to Mouse
	OrientCharacterToMouse();

	// Reset Movement Vector at the end of tick
	MovementVectorThisFrame = FVector::ZeroVector;
}

void AProjetTopDownCharacter::OrientCharacterToMouse()
{
	if (GetController() == nullptr || Cast<APlayerController>(GetController()) == nullptr)
		return;

	FHitResult TraceHitResult;

	Cast<APlayerController>(GetController())->GetHitResultUnderCursor(ECC_Visibility, true, TraceHitResult);

	FVector impactPointZEqualsCharacterZ = FVector(TraceHitResult.ImpactPoint.X, TraceHitResult.ImpactPoint.Y, GetActorLocation().Z);

	FRotator rot = (impactPointZEqualsCharacterZ - GetActorLocation()).ToOrientationRotator();

	SetActorRotation(rot);
}

void AProjetTopDownCharacter::SetupPlayerInputComponent(UInputComponent * _PlayerInputComponent)
{
	if (_PlayerInputComponent == nullptr)
		return;

	// Movement binding
	_PlayerInputComponent->BindAxis("MoveForward", this, &AProjetTopDownCharacter::OnMoveForwardAxis);
	_PlayerInputComponent->BindAxis("MoveRight", this, &AProjetTopDownCharacter::OnMoveRightAxis);

	// Skills binding
	_PlayerInputComponent->BindAction("Skill0", IE_Pressed, this, &AProjetTopDownCharacter::OnSkill0Input);
	_PlayerInputComponent->BindAction("Skill1", IE_Pressed, this, &AProjetTopDownCharacter::OnSkill1Input);
	_PlayerInputComponent->BindAction("Skill2", IE_Pressed, this, &AProjetTopDownCharacter::OnSkill2Input);
}

void AProjetTopDownCharacter::OnMoveForwardAxis(const float _value)
{
	MovementVectorThisFrame += FVector::ForwardVector * _value;
}

void AProjetTopDownCharacter::OnMoveRightAxis(const float _value)
{
	MovementVectorThisFrame += FVector::RightVector * _value;
}

void AProjetTopDownCharacter::OnSkill0Input()
{
	OnSkillRequested(0);
}

void AProjetTopDownCharacter::OnSkill1Input()
{
	OnSkillRequested(1);
}

void AProjetTopDownCharacter::OnSkill2Input()
{
	OnSkillRequested(2);
}

void AProjetTopDownCharacter::OnSkillRequested(const int32 _skillIndex)
{
	if (SkillManager)
		SkillManager->OnSkillRequested(_skillIndex);
	else
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("Character::OnSkillRequested :: No Skill Manager")));
}

void AProjetTopDownCharacter::UpdateWalkSpeed(float _newWalkSpeed)
{
	this->GetCharacterMovement()->MaxWalkSpeed = _newWalkSpeed;
}
