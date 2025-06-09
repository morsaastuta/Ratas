// Fill out your copyright notice in the Description page of Project Settings.

#include "Characters/RatasCharacterFoe.h"
#include "RatasWave.h"
#include "Characters/RatasCharacterPlayer.h"
#include "Components/ArrowComponent.h"

ARatasCharacterFoe::ARatasCharacterFoe(): OverlapRangeDetect(0), OverlapRangeAttack(0) {
	DetectionRange = CreateDefaultSubobject<USphereComponent>(TEXT("DetectionRange"));
	DetectionRange->SetupAttachment(RootComponent);
	DetectionRange->SetSphereRadius(OverlapRangeDetect);

	EngageRange = CreateDefaultSubobject<USphereComponent>(TEXT("EngageRange"));
	EngageRange->SetupAttachment(RootComponent);
	EngageRange->SetSphereRadius(OverlapRangeAttack);

	ShootPoint = CreateDefaultSubobject<UArrowComponent>(TEXT("ShootOrigin"));
	ShootPoint->SetupAttachment(RootComponent);
}

void ARatasCharacterFoe::LookAt(FVector Location) {
	TargetLocation = Location;
}

void ARatasCharacterFoe::BeginPlay() {
	Super::BeginPlay();
	DetectionRange->SetSphereRadius(OverlapRangeDetect);
	EngageRange->SetSphereRadius(OverlapRangeAttack);
}

bool ARatasCharacterFoe::CheckPlayer(UShapeComponent* Overlap, ARatasCharacterPlayer*& Player) {
	TArray<AActor*> OverlappingActors;
	Overlap->GetOverlappingActors(OverlappingActors, ARatasCharacterPlayer::StaticClass());
	if (!OverlappingActors.IsEmpty()) {
		Player = Cast<ARatasCharacterPlayer>(OverlappingActors[0]);
		return true;
	}
	return false;
}

void ARatasCharacterFoe::GetHit(const float Damage) {
	ChangeHealth(-Damage);
}

void ARatasCharacterFoe::ChangeHealth(const float Value) {
	if (!Dead) {
		//UE_LOGFMT(LogTemp, Log, "{Total} + {Value} = {Result}", ("Value" , Value), ("Total", Health), ("Result", Health + Value));
		Health = FMath::Clamp(Health + Value, 0, HealthMax);
		AfterChecks();
		if (Health <= 0) Die();
	}
}

void ARatasCharacterFoe::Die() {
	if (IsValid(AssignedWave)) AssignedWave->Deaths++;
	Dead = true;
}

void ARatasCharacterFoe::AfterChecks_Implementation() {}
