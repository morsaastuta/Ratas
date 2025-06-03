// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RatasPropBullet.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class RATAS_API ARatasPropBullet : public AActor {
	GENERATED_BODY()

	public:
		UPROPERTY(Category=Weapon, EditAnywhere)
		USphereComponent* Collider;

		UPROPERTY(Category=Weapon, EditAnywhere)
		UStaticMeshComponent* Mesh;

		UPROPERTY(Category=Weapon, BlueprintReadWrite, EditAnywhere)
		UProjectileMovementComponent* ProjectileMovement;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float Damage;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float Speed;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float DespawnTimer;

		UPROPERTY(Category=Weapon, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		FName TargetTag;

		ARatasPropBullet();

		UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

		virtual void Tick(float DeltaSeconds) override;
};
