// ©Ratas

#include "Props/RatasTrap.h"

// Sets default values
ARatasTrap::ARatasTrap() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	SplashCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereSplashCollider"));

	SplashCollider->SetupAttachment(RootComponent);
	Mesh->SetupAttachment(SplashCollider);
}
