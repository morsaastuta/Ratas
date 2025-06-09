// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RatasBullet.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UProjectileMovementComponent;

UCLASS()
class RATAS_API ARatasBullet : public AActor {
	GENERATED_BODY()

	public:
		UPROPERTY(Category=RatasPropBullet, EditAnywhere)
		USphereComponent* Collider;

		UPROPERTY(Category=RatasPropBullet, EditAnywhere)
		UStaticMeshComponent* Mesh;

		UPROPERTY(Category=RatasPropBullet, BlueprintReadWrite, EditAnywhere)
		UProjectileMovementComponent* ProjectileMovement;

		UPROPERTY(Category=RatasPropBullet, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float Damage;

		UPROPERTY(Category=RatasPropBullet, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float Speed;

		UPROPERTY(Category=RatasPropBullet, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float DespawnTimer;

		UPROPERTY(Category=RatasPropBullet, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		FName TargetTag;

		ARatasBullet();

		UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

		virtual void Tick(float DeltaSeconds) override;
};
