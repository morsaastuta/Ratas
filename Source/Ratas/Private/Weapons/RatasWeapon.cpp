// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/RatasWeapon.h"
#include "Ratas/Public/Characters/RatasCharacterPlayer.h"
#include "Logging/StructuredLog.h"


// Sets default values
ARatasWeapon::ARatasWeapon(): Damage(0), Delay(0)
{
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxColliderCoso"));
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &ARatasWeapon::OnBeginOverlap);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(CollisionBox);
}

void ARatasWeapon::OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass()->GetSuperClass() == ARatasCharacterPlayer::StaticClass())
	{
		CollisionBox->UnregisterComponent();
		ARatasCharacterPlayer* Player = Cast<ARatasCharacterPlayer>(OtherActor);
		Player->WeaponCurrent = this;
		AttachToComponent(Player->Camera, FAttachmentTransformRules (EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, false));
		
		Mesh->SetRelativeLocation(FVector(20.f, 20.f, -7.f));
		UE_LOGFMT(LogTemp, Log,"Me cogiste weonm");
	}
}