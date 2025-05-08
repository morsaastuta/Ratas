// Fill out your copyright notice in the Description page of Project Settings.




#include "Props/RatasBullet.h"
#include "Ratas/RatasCharacter.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Logging/StructuredLog.h"

ARatasBullet::ARatasBullet()
{
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereColliderCoso"));
	CollisionSphere->SetupAttachment(RootComponent);
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ARatasBullet::OnBeginOverlap);

		
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(CollisionSphere);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
}

/*
ARatasBullet::ARatasBullet(const int _Damage, const float _Speed, const bool _ProximityDamage): Damage(_Damage), Speed(_Speed), ProximityDamage(_ProximityDamage), DespawnTimer(1)
{
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ARatasBullet::OnBeginOverlap);
}
*/

void ARatasBullet::OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOGFMT(LogTemplateCharacter, Log,"{tag}", ("tag", TargetTag));
	UE_LOGFMT(LogTemplateCharacter, Log,"{tag}", ("tag", OtherComp->ComponentTags));

	if (OtherComp->ComponentHasTag(TargetTag))
	{
		UE_LOGFMT(LogTemplateCharacter, Log,"Hago 2");

		Cast<ARatasCharacter>(OtherActor)->GetHit(Damage);
		Destroy();
	}
}