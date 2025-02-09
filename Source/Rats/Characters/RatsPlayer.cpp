#include "RatsPlayer.h"
#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/SceneCaptureComponent2D.h"

ARatsPlayer::ARatsPlayer()
{
	SetValues(100, 1, 1);
	
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComponent->SetupAttachment(CameraComponent);
		
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(GetCapsuleComponent());
	CameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f));
	CameraComponent->bUsePawnControlRotation = true;
		
	EyeLeft = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Left eye"));
	EyeLeft->SetupAttachment(GetCapsuleComponent());
	EyeLeft->SetRelativeLocation(FVector(-10.f, 0.f, 60.f));
	EyeLeft->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
		
	EyeRight = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Right eye"));
	EyeRight->SetupAttachment(GetCapsuleComponent());
	EyeRight->SetRelativeLocation(FVector(-10.f, 0.f, 60.f));
	EyeRight->SetRelativeRotation(FRotator(0.f, 0.f, 0.f));
}

void ARatsPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void ARatsPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ARatsPlayer::UpdateFieldOfView()
{
	EyeLeft->FOVAngle = FieldOfView;
	EyeLeft->SetRelativeRotation(FRotator(-90.f, FieldOfView/2, -90.f));
	
	EyeRight->FOVAngle = FieldOfView;
	EyeLeft->SetRelativeRotation(FRotator(-90.f, -FieldOfView/2, -90.f));
}

