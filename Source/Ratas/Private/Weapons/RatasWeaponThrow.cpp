// ©Ratas

#include "Weapons/RatasWeaponThrow.h"

ARatasWeaponThrow::ARatasWeaponThrow()
{
	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Projection"));
	Mesh->SetupAttachment(GrabArea);
}

void ARatasWeaponThrow::BeginPlay()
{
	Super::BeginPlay();

	Qty = QtyMax;
	RechargeTime = RechargeTimeMax;
}

bool ARatasWeaponThrow::CheckTrigger()
{
	if (Super::CheckTrigger())
	{
		if (Qty > 0)
		{
			Qty--;
			return true;
		}
		return false;
	}
	return false;
}

void ARatasWeaponThrow::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	StaticMesh->SetActive(Qty > 0);
	
	if (Qty < QtyMax)
	{
		RechargeTime -= DeltaSeconds;
		if (RechargeTime <= 0)
		{
			RechargeTime += RechargeTimeMax;
			Qty++;
		}
	}
}