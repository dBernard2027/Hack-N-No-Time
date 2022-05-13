// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "ProjetTopDownGameMode.h"
#include "ProjetTopDownPlayerController.h"
#include "ProjetTopDownCharacter.h"
#include "UObject/ConstructorHelpers.h"

AProjetTopDownGameMode::AProjetTopDownGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AProjetTopDownPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Correction/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}