// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ExtractionZone.generated.h"

class UBoxComponent;
class USoundBase;

UCLASS()
class GERMANSHOOTER_API AExtractionZone : public AActor
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UBoxComponent* OverlapComp;

	UPROPERTY(EditAnywhere, Category = "Sounds")
	USoundBase* MissionCompleteSound;
	
	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent,AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
	
	const FVector defaultBoxSize = FVector(200.f);
	
public:	
	AExtractionZone();

};
