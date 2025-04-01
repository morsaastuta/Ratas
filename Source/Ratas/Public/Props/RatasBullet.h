// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RatasBullet.generated.h"

UCLASS()
class RATAS_API ARatasBullet : public AActor
{
	GENERATED_BODY()

public:
	
	UPROPERTY(Category=Weapon, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	int Damage;

	UPROPERTY(Category=Weapon, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(Category=Weapon, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	float DespawnTimer;
	
	// Sets default values for this actor's properties
	ARatasBullet(int _Damage, float _Speed, float _ReloadTimer, const FVector& _Location, const FRotator& _Rotation);

};
