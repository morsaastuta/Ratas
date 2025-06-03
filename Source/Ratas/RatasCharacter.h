// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "RatasCharacter.generated.h"

class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class ARatasCharacter : public ACharacter {
	GENERATED_BODY()

	public:
		ARatasCharacter();

	protected:
		virtual void BeginPlay() override;
		virtual void Tick(float DeltaTime) override;

		//Variables
	public:
		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
		UInputAction* MoveAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* LookAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Input, meta=(AllowPrivateAccess = "true"))
		UInputAction* JumpAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* TriggerAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* ReloadAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* NextWeaponAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* PrevWeaponAction;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* SelectWeaponAction1;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* SelectWeaponAction2;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* SelectWeaponAction3;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* SelectWeaponAction4;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Properties, meta = (AllowPrivateAccess = "true"))
		float Speed;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Properties, meta = (AllowPrivateAccess = "true"))
		float Acceleration;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Properties, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float HitCooldownMax;

		UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Properties, meta = (AllowPrivateAccess = true))
		float HitCooldown;

		//Functions
	protected:
		UFUNCTION(BlueprintCallable, Category="Ratas")
		virtual void Move(const FVector& Value);

		UFUNCTION(BlueprintCallable, Category="Ratas")
		virtual void Look(const FVector& Value);

	public:
		virtual void GetHit(float Damage);
};
