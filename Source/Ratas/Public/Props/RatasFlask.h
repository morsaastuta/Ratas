// ©Ratas

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "RatasFlask.generated.h"

UCLASS()
class RATAS_API ARatasFlask : public AActor {
	GENERATED_BODY()

	public:
		// Sets default values for this actor's properties
	ARatasFlask();

	UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
	USoundWave* FlaskBreakSound;

		UPROPERTY(Category = RatasPropFlask, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* Mesh;

		UPROPERTY(Category = RatasPropFlask, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;

		UPROPERTY(Category = RatasPropFlask, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = true))
		USphereComponent* SplashCollider;

		UPROPERTY(Category = RatasPropFlask, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float Speed;
	
	UFUNCTION()
	void OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION(BlueprintImplementableEvent)
	void OnDeath();
};
