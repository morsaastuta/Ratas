// ©Ratas

#include "Weapons/RatasWeaponThrow.h"

#include "Kismet/GameplayStatics.h"

ARatasWeaponThrow::ARatasWeaponThrow() {
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Projection"));
	Mesh->SetupAttachment(Bounds);
}

bool ARatasWeaponThrow::CheckTrigger() {
	if (Super::CheckTrigger()) {
		if (Qty > 0) {
			Qty--;
			UGameplayStatics::PlaySound2D(this, WeaponThrowSound);
			return true;
		}
		return false;
	}
	return false;
}

void ARatasWeaponThrow::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);

	Mesh->SetActive(Qty > 0);
	if (Qty < QtyMax) {
		RechargeTime -= DeltaSeconds;
		if (RechargeTime <= 0) {
			RechargeTime += RechargeTimeMax;
			Qty++;
		}
	}
}
