// ©Ratas

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"
#include "RatasTrap.generated.h"

UCLASS()
class RATAS_API ARatasTrap : public AActor {
	GENERATED_BODY()

	public:
		// Sets default values for this actor's properties
		ARatasTrap();

		UPROPERTY(Category=RatasPlayer, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		USoundWave* TrapBreakSound;

		UPROPERTY(Category = RatasPropTrap, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent* Mesh;

		UPROPERTY(Category = RatasPropTrap, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		UProjectileMovementComponent* ProjectileMovement;

		UPROPERTY(Category = RatasPropTrap, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = true))
		USphereComponent* SplashCollider;

		UPROPERTY(Category = RatasPropTrap, EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float Speed;
};
