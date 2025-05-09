// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/RatasWeapon.h"
#include "RatasWeaponRanged.generated.h"

class ARatasBullet;
/**
 * 
 */
UCLASS()
class RATAS_API ARatasWeaponRanged : public ARatasWeapon
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(Category=Weapon, EditAnywhere)
	AActor* Bullet;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	float ReloadTime;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	float Impulse;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	bool ProximityDamage;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	int AmmoMax;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	int Ammo;

	ARatasWeaponRanged();

	ARatasBullet* Shoot();
	
};