// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RatasBullet.generated.h"

class USphereComponent;

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

	UPROPERTY(Category=Weapon, VisibleAnywhere)
	USphereComponent* CollisionSphere;

	
	ARatasBullet();
	
	// Sets default values for this actor's properties
	ARatasBullet(int _Damage, float _Speed, float _ReloadTimer, const FVector& _Location, const FRotator& _Rotation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UFUNCTION()
	void OnBeginOverlap(class UPrimitiveComponent* Comp ,class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
