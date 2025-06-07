// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "RatasWeapon.generated.h"

class ARatasCharacterPlayer;
class AWave;

UCLASS()
class RATAS_API ARatasWeapon : public AActor {
	GENERATED_BODY()

	public:
		ARatasWeapon();

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn))
		AWave* NextWave;

		UPROPERTY(Category=Weapon, EditAnywhere, meta=(AllowPrivateAccess = "true"))
		UBoxComponent* Bounds;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		float Damage;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float RechargeTimeMax;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float RechargeTime;

		UFUNCTION()
		virtual bool CheckTrigger();

		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Ratas")
		void Trigger();

	protected:
		UPROPERTY(Category=Weapon, EditAnywhere, meta=(AllowPrivateAccess = "true"))
		float DelayMax;

		UPROPERTY(Category=Weapon, EditAnywhere, meta=(AllowPrivateAccess = "true"))
		float Delay;

		UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

		virtual void BeginPlay() override;

		void Grab(ARatasCharacterPlayer* Player);

		virtual void Tick(float DeltaSeconds) override;
};
