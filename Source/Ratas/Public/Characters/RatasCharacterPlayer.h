// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Ratas/RatasCharacter.h"
#include "RatasCharacterPlayer.generated.h"

UCLASS()
class RATAS_API ARatasCharacterPlayer : public ARatasCharacter
{
	GENERATED_BODY()

public:

	//Variables
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneCaptureComponent2D* EyeLeft;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USceneCaptureComponent2D* EyeRight;

	//UPROPERTY(EditDefaultsOnly, Category = "UI")
	//TSubclassOf<class UUserWidget> WidgetReference;
	
	UPROPERTY()
	UUserWidget* EyeBlend;
	
	ARatasCharacterPlayer();
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Tick(float DeltaTime) override;

protected:
	
	virtual void BeginPlay() override;
	
	void MoveInput(const FInputActionValue& Value);
	void LookInput(const FInputActionValue& Value);
	void ActInput(const FInputActionValue& Value);
	
	virtual void Move(const FVector2d& Value) override;
	virtual void Look(const FVector2d& Value) override;
	virtual void Act() override;
	
};
