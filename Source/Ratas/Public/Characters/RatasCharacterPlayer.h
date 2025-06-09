// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "Ratas/RatasCharacter.h"
#include "RatasCharacterPlayer.generated.h"

class ARatasWeapon;
class ARatasWarp;
class URatasViewport;

UCLASS()
class RATAS_API ARatasCharacterPlayer : public ARatasCharacter {
	GENERATED_BODY()

	public:
		//Variables
		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		bool Immortal = false;

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		bool HasEverMoved = false;

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float FOVAngleMax = 160;

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float AccelerationMin = 0.1f;

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float AccelerationMax = 6.0f;

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		UCameraComponent* Camera;

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		USceneCaptureComponent2D* EyeLeft;
		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		USceneCaptureComponent2D* EyeCenter;
		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		USceneCaptureComponent2D* EyeRight;

		UPROPERTY(Category=RatasPlayer, EditDefaultsOnly)
		TSubclassOf<class UUserWidget> WidgetReference;

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		UUserWidget* Viewport;

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		ARatasWeapon* WeaponCurrent;

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		TArray<ARatasWeapon*> Arsenal;

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		bool IsMoving;

		ARatasCharacterPlayer();

		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
		virtual void Tick(float DeltaTime) override;
		void AddWeapon(const ARatasWeapon* Weapon);

		UFUNCTION(Category=RatasPlayer, BlueprintCallable)
		virtual void GetHit(const float Damage) override;

		UFUNCTION(Category=RatasPlayer, BlueprintCallable)
		void ContactWarp(ARatasWarp* Warp);

		UFUNCTION(Category=RatasPlayer, BlueprintImplementableEvent)
		void ActivateWarp();

	protected:
		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		TSoftObjectPtr<UWorld> CurrentLevel;

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		TSoftObjectPtr<UWorld> NextLevel;

		virtual void BeginPlay() override;
		void SetWeapon(int Index);

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
