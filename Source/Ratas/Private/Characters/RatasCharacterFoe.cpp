// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/RatasCharacterFoe.h"
#include "Wave.h"
#include "Chaos/Utilities.h"
#include "Characters/RatasCharacterPlayer.h"
#include "Logging/StructuredLog.h"

ARatasCharacterFoe::ARatasCharacterFoe(): OverlapRangeDetect(0), OverlapRangeAttack(0)
{
	DetectionRange = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionRange"));
	DetectionRange->SetupAttachment(RootComponent);
	DetectionRange->SetSphereRadius(OverlapRangeDetect);

	EngageRange = CreateDefaultSubobject<USphereComponent>(TEXT("EngageRange"));
	EngageRange->SetupAttachment(RootComponent);
	EngageRange->SetSphereRadius(OverlapRangeAttack);
}

void ARatasCharacterFoe::LookAt(FVector Location)
{
	TargetLocation = Location;
}

void ARatasCharacterFoe::BeginPlay() 
{
	Super::BeginPlay();
	DetectionRange->SetSphereRadius(OverlapRangeDetect);
	EngageRange->SetSphereRadius(OverlapRangeAttack);
}

bool ARatasCharacterFoe::CheckPlayer(UShapeComponent* Overlap, ARatasCharacterPlayer*& Player)
{
	TArray<AActor*> OverlappingActors;
	
	Overlap->GetOverlappingActors(OverlappingActors,ARatasCharacterPlayer::StaticClass());

	if (!OverlappingActors.IsEmpty())
	{
		Player = Cast<ARatasCharacterPlayer>(OverlappingActors[0]);
		return true;
	}
	return false;
}

void ARatasCharacterFoe::ChangeHealth(int Value)
{
	Super::ChangeHealth(Value);

	AfterChecks();
}

void ARatasCharacterFoe::Die()
{
	if (AssignedWave != nullptr)
	{
		AssignedWave->Deaths++;
	}
}

void ARatasCharacterFoe::AfterChecks_Implementation()
{
}
