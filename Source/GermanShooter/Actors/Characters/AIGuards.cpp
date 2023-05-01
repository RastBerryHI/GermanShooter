// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuards.h"

#include "Perception/PawnSensingComponent.h"

AAIGuards::AAIGuards()
{
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->OnSeePawn.AddDynamic(this, &AAIGuards::OnPawnSeen);
	PawnSensingComp->OnHearNoise.AddDynamic(this, &AAIGuards::OnPawnHeard);
}

void AAIGuards::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAIGuards::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AAIGuards::OnPawnSeen(APawn* SeenPawn)
{
	if (!SeenPawn)
	{
		return;
	}

	DrawDebugSphere(
		GetWorld(),
		SeenPawn->GetActorLocation(),
		32.f,
		50,
		FColor::Yellow,
		false,
		10.f
	);
}

void AAIGuards::OnPawnHeard(APawn* PawnInstigator, const FVector& Location, float Volume)
{
	if (!PawnInstigator)
	{
		return;
	}

	DrawDebugSphere(
		GetWorld(),
		PawnInstigator->GetActorLocation(),
		32.f,
		50,
		FColor::Red,
		false,
		10.f
	);
}


