// Copyright Epic Games, Inc. All Rights Reserved.

#include "RatasCharacter.h"
#include "Animation/AnimInstance.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/LocalPlayer.h"

DEFINE_LOG_CATEGORY(LogTemplateCharacter);

ARatasCharacter::ARatasCharacter() {
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);
}

void ARatasCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	if (HitCooldown <= HitCooldownMax) HitCooldown += DeltaTime;
}

void ARatasCharacter::Move(const FVector& Value) {
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
}

void ARatasCharacter::Look(const FVector& Value) {
	AddControllerYawInput(Value.X);
	AddControllerPitchInput(Value.Y);
}

void ARatasCharacter::GetHit(float Damage) {}
