// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ProjetTopDownPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "ProjetTopDownCharacter.h"
#include "Engine/World.h"

AProjetTopDownPlayerController::AProjetTopDownPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}




