// Copyright Epic Games, Inc. All Rights Reserved.

#include "GermanShooterGameMode.h"
#include "GermanShooterCharacter.h"
#include "UObject/ConstructorHelpers.h"

AGermanShooterGameMode::AGermanShooterGameMode()
	: Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void AGermanShooterGameMode::CompleteMission(APawn* pawn)
{
	if (pawn)
	{
		pawn->DisableInput(nullptr);
		OnMissionCompleted(pawn);
	}
}
