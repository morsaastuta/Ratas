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

UCLASS()
class RATAS_API ARatasCharacterFoe : public ARatasCharacter
{
	GENERATED_BODY()

	//Functions
public:
	ARatasCharacterFoe();
	
protected:

	UPROPERTY(Category=Detector, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	float OverlapRangeDetect;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	USphereComponent* OverlapCompDetect;
	
	UPROPERTY(Category=Detector, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	float OverlapRangeAttack;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	USphereComponent* OverlapCompAttack;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	FVector TargetLocation;
	
	UFUNCTION(BlueprintCallable, Category="Ratas")
	bool DetectPlayer();

	UFUNCTION(BlueprintCallable, Category="Ratas")
	bool AttackPlayer();

	void LookAt(FVector Location);

	virtual void ChangeHealth(int Value) override;

	UFUNCTION(BlueprintNativeEvent, Category="Ratas")
	void AfterChecks();
};
