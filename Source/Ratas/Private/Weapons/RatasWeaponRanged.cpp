// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/RatasWeaponRanged.h"

#include "Logging/StructuredLog.h"
#include "Props/RatasBullet.h"

ARatasWeaponRanged::ARatasWeaponRanged(): Bullet(nullptr), ReloadTime(0), Impulse(0), ProximityDamage(false),
                                          AmmoMax(0), Ammo(0)
{
	
}

ARatasBullet* ARatasWeaponRanged::Shoot()
{

//ARatasBullet* bala = new ARatasBullet(Damage, Impulse, ProximityDamage);
	
	return nullptr;
	//return new ARatasBullet(Damage, Impulse, ProximityDamage);
}