// Fill out your copyright notice in the Description page of Project Settings.

#include "Weapons/RatasWeapon.h"
#include "Ratas/Public/Characters/RatasCharacterPlayer.h"

// Sets default values
ARatasWeapon::ARatasWeapon()
{
	GrabArea = CreateDefaultSubobject<UBoxComponent>(TEXT("GrabArea"));
	GrabArea->OnComponentBeginOverlap.AddDynamic(this, &ARatasWeapon::OnBeginOverlap);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Body"));
	Mesh->SetupAttachment(GrabArea);
}

void ARatasWeapon::BeginPlay()
{
	Super::BeginPlay();

	Delay = 0;
}

bool ARatasWeapon::CheckTrigger()
{
	if (Delay <= 0)
	{
		Delay = DelayMax;
		return true;
	}
	return false;
}

void ARatasWeapon::OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(ARatasCharacterPlayer::StaticClass()))
	{
		GrabArea->UnregisterComponent();
		ARatasCharacterPlayer* Player = Cast<ARatasCharacterPlayer>(OtherActor);
		Player->AddWeapon(this);
		AttachToComponent(Player->Camera, FAttachmentTransformRules (EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, false));
		Mesh->SetRelativeLocation(FVector(20.f, 20.f, -7.f));
	}
}

void ARatasWeapon::Tick(float DeltaSeconds)
{
	if (Delay > 0)
	{
		Delay -= DeltaSeconds;
	}
}