// ©Ratas

#pragma once

#include "CoreMinimal.h"
#include "Weapons/RatasWeapon.h"
#include "RatasWeaponThrow.generated.h"

/**
 * 
 */
UCLASS()
class RATAS_API ARatasWeaponThrow : public ARatasWeapon
{
	GENERATED_BODY()
	
public:

	ARatasWeaponThrow();

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<UMeshComponent> StaticMesh;
	
	UPROPERTY(Category=Weapon, EditAnywhere)
	AActor* Item;

	virtual bool CheckTrigger() override;

protected:
	
	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	float RechargeTimeMax;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	float RechargeTime;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	int QtyMax;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	int Qty;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
};
