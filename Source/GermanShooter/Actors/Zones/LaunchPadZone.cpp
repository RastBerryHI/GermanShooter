// Fill out your copyright notice in the Description page of Project Settings.


#include "LaunchPadZone.h"

#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

ALaunchPadZone::ALaunchPadZone()
{
	PrimaryActorTick.bCanEverTick = false;

	OverlapComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	OverlapComponent->SetCollisionResponseToChannels(ECR_Ignore);
	OverlapComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComponent->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
	OverlapComponent->SetBoxExtent(FVector(200, 200, 200));
	RootComponent = OverlapComponent;

	OverlapComponent->OnComponentBeginOverlap.AddDynamic(this, &ALaunchPadZone::HandleOverlap);
}

void ALaunchPadZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap"));

	ACharacter* Character = Cast<ACharacter>(OtherActor);
	if (Character)
	{
		Character->LaunchCharacter(FVector(1000, 1000, 1000), false, false);
		return;
	}

	OtherComp->AddImpulse(FVector(1000, 1000, 1000) * 100);
}

