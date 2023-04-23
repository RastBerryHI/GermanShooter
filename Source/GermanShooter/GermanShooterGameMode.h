// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GermanShooterGameMode.generated.h"

UCLASS(minimalapi)
class AGermanShooterGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGermanShooterGameMode();

	UFUNCTION(BlueprintImplementableEvent, Category = "GameMode")
	void OnMissionCompleted(APawn* pawn);
	
	void CompleteMission(APawn* pawn);
};



