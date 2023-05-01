// Fill out your copyright notice in the Description page of Project Settings.


#include "AIGuards.h"

#include "Perception/PawnSensingComponent.h"

AAIGuards::AAIGuards()
{
	PrimaryActorTick.bCanEverTick = true;

	PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
}

void AAIGuards::BeginPlay()
{
	Super::BeginPlay();
	
}

void AAIGuards::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


