// Copyright Epic Games, Inc. All Rights Reserved.

#include "RatasCharacter.h"
#include "Animation/AnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/LocalPlayer.h"

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


void ARatasCharacter::Move(const FVector2d& Value)
{
	const float Horizontal = Value.X;
	const float Vertical = Value.Y;

	// Find out which way is forward
	const FRotator Rotation = Controller->GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);
 
	// Get forward vector
	const FVector DirectionH = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	// Get right vector
	const FVector DirectionV = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	AddMovementInput(DirectionH, Horizontal * Speed);
	AddMovementInput(DirectionV, Vertical * Speed);
}

void ARatasCharacter::Look(const FVector2d& Value)
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

void ARatasCharacter::Die()
{
	printf("DIE");
}
