#include "RatsFoe.h"

ARatsFoe::ARatsFoe()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARatsFoe::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ARatsFoe::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

