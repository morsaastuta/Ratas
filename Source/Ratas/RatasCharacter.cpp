// Copyright Epic Games, Inc. All Rights Reserved.

#include "RatasCharacter.h"
#include "Animation/AnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/LocalPlayer.h"
#include "Logging/StructuredLog.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

//////////////////////////////////////////////////////////////////////////
// ARatasCharacter

ARatasCharacter::ARatasCharacter()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	Acceleration = 1.f;
	Speed = 1.f;
	HealthMax = 1.f;
	Health = 1.f;
	
	
	//Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	//Mesh1P->SetOnlyOwnerSee(true);
	
	//Mesh1P->bCastDynamicShadow = false;
	//Mesh1P->CastShadow = false;
	//Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	//Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));

}

void ARatasCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ARatasCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (HitCooldown <= HitCooldownMax) HitCooldown += DeltaTime;
}

void ARatasCharacter::Move(const FVector& Value)
{
	const float Frontal = Value.X;
	const float Lateral = Value.Y;
	const float Vertical = Value.Z;

	// Find out which way is forward
	const FRotator Rot = Controller->GetControlRotation();
	const FRotator RotYaw(0, Rot.Yaw, 0);
 
	// Get forward vector
	const FVector DirFrontal = FRotationMatrix(RotYaw).GetUnitAxis(EAxis::Y);
	AddMovementInput(DirFrontal, Frontal * Speed * Acceleration);
	
	// Get right vector
	const FVector DirLateral = FRotationMatrix(RotYaw).GetUnitAxis(EAxis::X);
	AddMovementInput(DirLateral, Lateral * Speed * Acceleration);
	
	// Get up vector
	const FVector DirVertical = FRotationMatrix(RotYaw).GetUnitAxis(EAxis::Z);
	AddMovementInput(DirVertical, Vertical * Speed * Acceleration);
	
	
	//UE_LOGFMT(LogTemplateCharacter, Log, "{Value}", ("Value" , GetVelocity().ToString()));

}

void ARatasCharacter::Look(const FVector& Value)
{
	AddControllerYawInput(Value.X);
	AddControllerPitchInput(Value.Y);
}

void ARatasCharacter::Act()
{
	
}

void ARatasCharacter::ChangeHealth(const int Value)
{
	if (Value < 0) printf("Dao");
	else if (Value > 0) printf("Cure" + Value);
	else printf("?????????????" + Value);
	
	Health = FMath::Clamp(Health + Value, 0, HealthMax);
	
	if (Health <= 0)
	{
		Die();
	}
}

void ARatasCharacter::GetHit(const int Value)
{
	if (HitCooldown >= HitCooldownMax)
	{
		UE_LOGFMT(LogTemplateCharacter, Log,"Me disyte weonm");
		HitCooldown = 0;
		ChangeHealth(Value);
	}
}

void ARatasCharacter::Die()
{
	printf("DIE");
}
