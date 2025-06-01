// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Weapons/RatasWeapon.h"
#include "RatasWeaponRanged.generated.h"

class ARatasBullet;

UCLASS()
class RATAS_API ARatasWeaponRanged : public ARatasWeapon
{
	GENERATED_BODY()
	
public:

	ARatasWeaponRanged();

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> Mesh;
	
	UPROPERTY(Category=Weapon, EditAnywhere)
	AActor* Bullet;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	float Impulse;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	int MagMax;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	int Mag;

	virtual bool CheckTrigger() override;

	UFUNCTION()
	void Reload();

protected:

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	bool Reloading;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
};