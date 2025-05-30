// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Ratas/RatasCharacter.h"
#include "RatasCharacterFoe.generated.h"

/**
 * 
 */
class USphereComponent;
class AWave;

UCLASS()
class RATAS_API ARatasCharacterFoe : public ARatasCharacter
{
	GENERATED_BODY()

	//Functions
public:
	ARatasCharacterFoe();
	
	UFUNCTION(BlueprintCallable, Category="Ratas")
	void LookAt(FVector Location);

	UPROPERTY(Category=Detector, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	AWave* AssignedWave;
	
protected:

	UPROPERTY(Category=Detector, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	float OverlapRangeDetect;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	USphereComponent* DetectionRange;
	
	UPROPERTY(Category=Detector, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	float OverlapRangeAttack;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	USphereComponent* EngageRange;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	FVector TargetLocation;

	UFUNCTION(BlueprintCallable, Category="Ratas")
	bool CheckPlayer(UShapeComponent* Overlap, ARatasCharacterPlayer*& Player);
	
	virtual void Die() override;

	virtual void ChangeHealth(int Value) override;

	UFUNCTION(BlueprintNativeEvent, Category="Ratas")
	void AfterChecks();
};
