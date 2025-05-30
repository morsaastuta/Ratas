// ©Ratas

#include "Wave.h"
#include "Characters/RatasCharacterFoe.h"

AWave::AWave()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AWave::BeginPlay()
{
	Super::BeginPlay();
	
	for (ARatasCharacterFoe* Foe : Foes)
	{
		Foe->AssignedWave = this;
		Foe->GetRootComponent()->SetActive(false);
	}
}

void AWave::Begin()
{
	for (ARatasCharacterFoe* Foe : Foes)
	{
		Foe->GetRootComponent()->SetActive(true);
	}
}

void AWave::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Deaths >= Foes.Num()) End();
}

void AWave::End()
{
	for (AWave* Wave : NextWave)
	{
		Wave->Begin();
	}
}

