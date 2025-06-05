// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Ratas/RatasCharacter.h"
#include "RatasCharacterPlayer.generated.h"

class ARatasWeapon;

UCLASS()
class RATAS_API ARatasCharacterPlayer : public ARatasCharacter {
	GENERATED_BODY()

	public:
		//Variables
		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		bool Immortal = false;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		bool HasEverMoved = false;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float FOVAngleMax = 160;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float AccelerationMin = 0.1f;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float AccelerationMax = 6.0f;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		UCameraComponent* Camera;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		USceneCaptureComponent2D* EyeLeft;
		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		USceneCaptureComponent2D* EyeRight;

		UPROPERTY(EditDefaultsOnly, Category = "UI")
		TSubclassOf<class UUserWidget> WidgetReference;

		UPROPERTY()
		UUserWidget* Viewport;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		ARatasWeapon* WeaponCurrent;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		TArray<ARatasWeapon*> Arsenal;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		bool IsMoving;

		ARatasCharacterPlayer();

		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
		virtual void Tick(float DeltaTime) override;
		void AddWeapon(ARatasWeapon* Weapon);

		UFUNCTION(BlueprintCallable, Category="Ratas")
		virtual void GetHit(const float Damage) override;

		UFUNCTION(BlueprintImplementableEvent, Category = "RatasCallback")
		void CallbackChangeWeapon();

	protected:
		virtual void BeginPlay() override;
		void SetWeapon(int index);

		void MoveInput(const FInputActionValue& Value);
		void LookInput(const FInputActionValue& Value);
		void StopInput();

		void TriggerInput();
		void ReloadInput();

		void NextWeaponInput();
		void PrevWeaponInput();
		void SelectWeaponInput1();
		void SelectWeaponInput2();
		void SelectWeaponInput3();
		void SelectWeaponInput4();
};
