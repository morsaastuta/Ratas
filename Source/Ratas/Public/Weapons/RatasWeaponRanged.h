// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/RatasWeapon.h"
#include "RatasWeaponRanged.generated.h"

/**
 * 
 */
UCLASS()
class RATAS_API ARatasWeaponRanged : public ARatasWeapon
{
	GENERATED_BODY()
public:

	UPROPERTY(Category=Weapon, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	int Ammo;

	UPROPERTY(Category=Weapon, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	float ReloadTime;
	
	UPROPERTY(Category=Weapon, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	AActor* Bullet;
	
};
