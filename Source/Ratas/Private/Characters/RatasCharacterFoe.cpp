// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/RatasCharacterFoe.h"
#include "Chaos/Utilities.h"
#include "Characters/RatasCharacterPlayer.h"
#include "Logging/StructuredLog.h"

ARatasCharacterFoe::ARatasCharacterFoe(): OverlapRange(0)
{
	OverlapComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereOverlap"));
	OverlapComp->SetupAttachment(RootComponent);
}

void ARatasCharacterFoe::LookAt(FVector Location)
{
	TargetLocation = Location;
}

void ARatasCharacterFoe::BeginPlay() 
{
	Super::BeginPlay();
	OverlapComp->SetSphereRadius(OverlapRange);
}

bool ARatasCharacterFoe::DetectPlayer()
{
	TArray<AActor*> OverlappingActors;
	
	OverlapComp->GetOverlappingActors(OverlappingActors,ARatasCharacterPlayer::StaticClass());

	if (!OverlappingActors.IsEmpty())
	{
		LookAt(OverlappingActors[0]->GetActorLocation());
		return true;
	}
	return false;
}
