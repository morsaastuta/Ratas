#pragma once

#include "CoreMinimal.h"
#include "Rats/RatsCharacter.h"
#include "RatsFoe.generated.h"

UCLASS(config=Game)
class RATS_API ARatsFoe : public ARatsCharacter
{
	GENERATED_BODY()

public:
	
	ARatsFoe();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
