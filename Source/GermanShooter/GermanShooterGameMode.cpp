// Copyright Epic Games, Inc. All Rights Reserved.

#include "GermanShooterGameMode.h"
#include "GermanShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGermanShooterGameMode::AGermanShooterGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
