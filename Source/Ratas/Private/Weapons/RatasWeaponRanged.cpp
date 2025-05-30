// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons/RatasWeaponRanged.h"

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
	ReloadTime = ReloadTimeMax;
}

void ARatasWeaponRanged::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (Reloading)
	{
		ReloadTime -= DeltaSeconds;
	
		if (ReloadTime <= 0)
		{
			Reloading = false;
			Mag = MagMax;
		}
	}
}