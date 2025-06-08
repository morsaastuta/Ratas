// Fill out your copyright notice in the Description page of Project Settings.

#include "Props/RatasPropBullet.h"
#include "Ratas/RatasCharacter.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

ARatasPropBullet::ARatasPropBullet() {
	Collider = CreateDefaultSubobject<USphereComponent>(TEXT("Collider"));
	Collider->SetupAttachment(RootComponent);
	Collider->OnComponentBeginOverlap.AddDynamic(this, &ARatasPropBullet::OnBeginOverlap);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collider);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
}

void ARatasPropBullet::OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (OtherComp->ComponentHasTag(TargetTag)) {
		Cast<ARatasCharacter>(OtherActor)->GetHit(Damage);
		Destroy();
	}
}

void ARatasPropBullet::Tick(float DeltaSeconds) {
	DespawnTimer -= DeltaSeconds;
	if (DespawnTimer <= 0) {
		Destroy();
	}
	Super::Tick(DeltaSeconds);
}