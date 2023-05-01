// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuards.h"

#include "Perception/PawnSensingComponent.h"

AAIGuards::AAIGuards()
{
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
	PawnSensingComp->OnSeePawn.AddDynamic(this, &AAIGuards::OnPawnSeen);
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
	if (SeenPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("Seen Pawn"));
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
}


