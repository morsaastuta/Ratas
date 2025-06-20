// ©Ratas

#pragma once

#include "CoreMinimal.h"
#include "Weapons/RatasWeapon.h"
#include "RatasWeaponThrow.generated.h"

UCLASS()
class RATAS_API ARatasWeaponThrow : public ARatasWeapon {
	GENERATED_BODY()

	public:
		ARatasWeaponThrow();

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		USoundWave* WeaponThrowSound;

		UPROPERTY(Category=RatasWeaponThrow, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		TObjectPtr<UStaticMeshComponent> Mesh;

		UPROPERTY(Category=RatasWeaponThrow, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		TSubclassOf<AActor> Item;

		virtual bool CheckTrigger() override;

		UPROPERTY(Category=RatasWeaponThrow, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		int QtyMax;

		UPROPERTY(Category=RatasWeaponThrow, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		int Qty;

	protected:
		virtual void Tick(float DeltaSeconds) override;
};
