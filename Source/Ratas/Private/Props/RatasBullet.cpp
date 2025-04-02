// Fill out your copyright notice in the Description page of Project Settings.



#include "Logging/StructuredLog.h"
#include "Ratas/RatasCharacter.h"
#include "Props/RatasBullet.h"
#include "Components/SphereComponent.h"

ARatasBullet::ARatasBullet()
{
	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereColliderCoso"));
	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &ARatasBullet::OnBeginOverlap);
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
	if (OtherActor->GetClass()->GetSuperClass()->GetSuperClass() == ARatasCharacter::StaticClass())
	{
		UE_LOGFMT(LogTemplateCharacter, Log,"Me disyte weonm");
	}
}