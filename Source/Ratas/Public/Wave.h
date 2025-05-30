// ©Ratas

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Wave.generated.h"

class ARatasCharacterFoe;

UCLASS()
class RATAS_API AWave : public AActor
{
	GENERATED_BODY()
	
public:
	TArray<ARatasCharacterFoe*> Foes;
	TArray<AWave*> NextWave;
	int Deaths = 0;
	AWave();
	void Begin();
	void End();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

};
