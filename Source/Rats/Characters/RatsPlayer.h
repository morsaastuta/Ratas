#pragma once

#include "CoreMinimal.h"
#include "Rats/RatsCharacter.h"
#include "RatsPlayer.generated.h"

class UCameraComponent;
class USceneCaptureComponent2D;

UCLASS(config=Game)
class RATS_API ARatsPlayer : public ARatsCharacter
{
	GENERATED_BODY()

protected:
	
	float FieldOfView;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneCaptureComponent2D* EyeLeft;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneCaptureComponent2D* EyeRight;
	
	UFUNCTION(BlueprintCallable)
	void UpdateFieldOfView();

public:
	ARatsPlayer();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
