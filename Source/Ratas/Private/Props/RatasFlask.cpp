// ©Ratas


#include "Props/RatasFlask.h"

#include "Kismet/GameplayStatics.h"
#include "Logging/StructuredLog.h"

// Sets default values
ARatasFlask::ARatasFlask() {
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	SplashCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereSplashCollider"));

	SplashCollider->SetupAttachment(RootComponent);
	Mesh->SetupAttachment(SplashCollider);

	SplashCollider->OnComponentBeginOverlap.AddDynamic(this, &ARatasFlask::OnBeginOverlap);
}

void ARatasFlask::OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                     const FHitResult& SweepResult) {
	if (!(OtherActor->ActorHasTag("Player"))) {
		OnDeath();
		UGameplayStatics::PlaySound2D(this, FlaskBreakSound);
		Destroy();
	}
}
