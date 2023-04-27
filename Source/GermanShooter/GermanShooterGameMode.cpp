// Copyright Epic Games, Inc. All Rights Reserved.

#include "GermanShooterGameMode.h"
#include "GermanShooterCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AGermanShooterGameMode::AGermanShooterGameMode()
	: Super()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void AGermanShooterGameMode::CompleteMission(APawn* pawn)
{
	if (!pawn)
	{
		return;
	}

	pawn->DisableInput(nullptr);
	OnMissionCompleted(pawn);

	if (APlayerController* PC = Cast<APlayerController>(pawn->GetController()))
	{
		TArray<AActor*> OutActors;

		if (!SpectatingViewPoint)
		{
			return;
		}
		
		UGameplayStatics::GetAllActorsOfClass(this, SpectatingViewPoint, OutActors);
		if (OutActors.Num())
		{
			PC->SetViewTargetWithBlend(OutActors[0], 0.5f, EViewTargetBlendFunction::VTBlend_Cubic);
		}
	}
}
