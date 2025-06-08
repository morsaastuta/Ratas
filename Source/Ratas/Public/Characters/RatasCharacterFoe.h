// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Ratas/RatasCharacter.h"
#include "RatasCharacterFoe.generated.h"

class USphereComponent;
class ARatasWave;

UCLASS()
class RATAS_API ARatasCharacterFoe : public ARatasCharacter {
	GENERATED_BODY()

	//Functions
	public:
		ARatasCharacterFoe();

		UFUNCTION(Category=RatasFoe, BlueprintCallable)
		void LookAt(FVector Location);

		UPROPERTY(Category=RatasFoe, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		ARatasWave* AssignedWave;

		UPROPERTY(Category=RatasFoe, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float Health;

		UPROPERTY(Category=RatasFoe, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
		float HealthMax;

		UPROPERTY(Category=RatasFoe, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = true))
		UArrowComponent* ShootPoint;

		UFUNCTION(Category=RatasFoe, BlueprintCallable)
		virtual void GetHit(float Damage) override;

	protected:
		bool Dead = false;

		UPROPERTY(Category=RatasFoe, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float OverlapRangeDetect;

		UPROPERTY(Category=RatasFoe, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		USphereComponent* DetectionRange;

		UPROPERTY(Category=RatasFoe, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float OverlapRangeAttack;

		UPROPERTY(Category=RatasFoe, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		USphereComponent* EngageRange;

		virtual void BeginPlay() override;

		UPROPERTY(Category=RatasFoe, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		FVector TargetLocation;

		UFUNCTION(Category=RatasFoe, BlueprintCallable)
		bool CheckPlayer(UShapeComponent* Overlap, ARatasCharacterPlayer*& Player);

		UFUNCTION(Category=RatasFoe, BlueprintCallable)
		virtual void ChangeHealth(const float Value);

		UFUNCTION(Category=RatasFoe, BlueprintCallable)
		virtual void Die();

		UFUNCTION(Category=RatasFoe, BlueprintNativeEvent)
		void AfterChecks();
};
