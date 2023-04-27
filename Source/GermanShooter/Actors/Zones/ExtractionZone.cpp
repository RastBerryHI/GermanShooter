

#include "ExtractionZone.h"
#include "Components/BoxComponent.h"
#include "GermanShooter/GermanShooterCharacter.h"
#include "GermanShooter/GermanShooterGameMode.h"
#include "Kismet/GameplayStatics.h"

AExtractionZone::AExtractionZone()
{
	OverlapComp = CreateDefaultSubobject<UBoxComponent>(TEXT("OverlapComp"));
	OverlapComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	OverlapComp->SetCollisionResponseToChannels(ECR_Ignore);
	OverlapComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	OverlapComp->SetBoxExtent(defaultBoxSize);
	RootComponent = OverlapComp;

	OverlapComp->OnComponentBeginOverlap.AddDynamic(this, &AExtractionZone::HandleOverlap);
}

void AExtractionZone::HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AGermanShooterCharacter* GermanPawn = Cast<AGermanShooterCharacter>(OtherActor);
	if (!GermanPawn)
	{
		return;
	}

	AGermanShooterGameMode* GermanGameMode = Cast<AGermanShooterGameMode>(GetWorld()->GetAuthGameMode());
	if (GermanGameMode)
	{
		GermanGameMode->CompleteMission(GermanPawn);
	}

	if (MissionCompleteSound)
	{
		UGameplayStatics::PlaySound2D(this, MissionCompleteSound);
	}
}


