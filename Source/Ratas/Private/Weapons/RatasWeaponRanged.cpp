// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons/RatasWeaponRanged.h"

#include "Logging/StructuredLog.h"

ARatasWeaponRanged::ARatasWeaponRanged() {
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Body"));
	Mesh->SetupAttachment(Bounds);

	Barrel = CreateDefaultSubobject<UArrowComponent>(TEXT("Barrel"));
	Barrel->SetupAttachment(Mesh);
}

bool ARatasWeaponRanged::CheckTrigger() {
	if (Super::CheckTrigger()) {
		if (Mag > 0) {
			Mag--;
			return true;
		}
		return false;
	}
	return false;
}

void ARatasWeaponRanged::Reload() {
	Reloading = true;
}

void ARatasWeaponRanged::Recharge() {
	Reloading = false;
	Mag = MagMax;
}

void ARatasWeaponRanged::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	
}