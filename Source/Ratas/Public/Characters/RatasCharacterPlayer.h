// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Ratas/RatasCharacter.h"
#include "RatasCharacterPlayer.generated.h"

class ARatasWeapon;

UCLASS()
class RATAS_API ARatasCharacterPlayer : public ARatasCharacter
{
	GENERATED_BODY()

public:

	//Variables
	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	UCameraComponent* Camera;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	UArrowComponent* Eyes;

	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	USceneCaptureComponent2D* EyeLeft;
	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	USceneCaptureComponent2D* EyeRight;

	UPROPERTY(EditDefaultsOnly, Category = "UI")
	TSubclassOf<class UUserWidget> WidgetReference;
	
	UPROPERTY()
	UUserWidget* EyeBlend;
	
	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	ARatasWeapon* WeaponCurrent;
	
	UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	bool IsMoving;
	
	ARatasCharacterPlayer();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

protected:
	
	virtual void BeginPlay() override;
	
	void MoveInput(const FInputActionValue& Value);
	void LookInput(const FInputActionValue& Value);
	void ActInput(const FInputActionValue& Value);
	void StopInput(const FInputActionValue& _);

	
};
