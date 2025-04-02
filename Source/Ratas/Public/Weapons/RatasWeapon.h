// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "RatasWeapon.generated.h"

UCLASS()
class RATAS_API ARatasWeapon : public AActor
{
	GENERATED_BODY()
	
public:

	UPROPERTY(Category=Character, EditAnywhere, meta=(AllowPrivateAccess = "true"))
	TObjectPtr<USkeletalMeshComponent> Mesh;

	UPROPERTY(Category=Weapon, EditAnywhere, meta=(AllowPrivateAccess = "true"))
	UBoxComponent* CollisionBox;
		
	UPROPERTY(Category=Weapon, EditAnywhere, meta=(AllowPrivateAccess = "true"))
	int Damage;

	UPROPERTY(Category=Weapon, EditAnywhere, meta=(AllowPrivateAccess = "true"))
	float Delay;

	ARatasWeapon();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Ratas")
	void Trigger();

	UFUNCTION()
	void OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
