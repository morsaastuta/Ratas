// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons/RatasWeaponRanged.h"

ARatasWeaponRanged::ARatasWeaponRanged()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Body"));
	Mesh->SetupAttachment(Bounds);
}

void ARatasWeaponRanged::BeginPlay()
{
	Super::BeginPlay();

	Mag = MagMax;
}

bool ARatasWeaponRanged::CheckTrigger()
{
	if (Super::CheckTrigger())
	{
		if (Mag > 0)
		{
			Mag--;
			return true;
		}
		return false;
	}
	return false;
}

void ARatasWeaponRanged::Reload()
{
	Reloading = true;
	RechargeTime = RechargeTimeMax;
}

void ARatasWeaponRanged::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (Reloading)
	{
		RechargeTime -= DeltaSeconds;
	
		if (RechargeTimeMax <= 0)
		{
			Reloading = false;
			Mag = MagMax;
		}
	}
}