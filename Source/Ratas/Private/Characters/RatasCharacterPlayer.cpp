#include "Characters/RatasCharacterPlayer.h"
#include "EnhancedInputComponent.h"
#include "Blueprint/UserWidget.h"
#include "Weapons/RatasWeaponRanged.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
ARatasCharacterPlayer::ARatasCharacterPlayer() {
	PrimaryActorTick.bCanEverTick = true;

	// Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetCapsuleComponent());
	Camera->SetRelativeLocation(FVector(-10.f, 0.f, 60.f));
	Camera->bUsePawnControlRotation = true;
	GetMesh()->SetupAttachment(Camera);

	// Eyes
	EyeLeft = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("EyeLeft"));
	EyeRight = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("EyeRight"));
	EyeLeft->SetupAttachment(GetCapsuleComponent());
	EyeRight->SetupAttachment(GetCapsuleComponent());
	EyeLeft->SetRelativeLocation(FVector(-10.f, 0.f, 60.f));
	EyeRight->SetRelativeLocation(FVector(-10.f, 0.f, 60.f));
	// Eye blend
	if (IsValid(WidgetReference)) {
		Viewport = CreateWidget(GetWorld(), WidgetReference);
	}

	if (IsValid(Viewport)) {
		Viewport->AddToViewport();
	}

	IsMoving = false;
}

void ARatasCharacterPlayer::BeginPlay() {
	Super::BeginPlay();
	// Eye blend
	if (IsValid(WidgetReference)) {
		Viewport = CreateWidget(GetWorld(), WidgetReference);
	}

	if (IsValid(Viewport)) {
		Viewport->AddToViewport();
	}
}

void ARatasCharacterPlayer::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (HasEverMoved) {
		Acceleration = GetCharacterMovement()->GetLastUpdateVelocity() != FVector(0, 0, 0)
			               ? FMath::Clamp(Acceleration + 0.01f, 0.f, AccelerationMax)
			               : FMath::Clamp(Acceleration - 0.01f, 0.f, AccelerationMax);
		if (Immortal && Acceleration <= 0) {
			Acceleration = AccelerationMin;
		}

		GetCharacterMovement()->MaxAcceleration = Acceleration * 200.f;

		EyeLeft->SetRelativeRotation(FRotator(EyeLeft->GetRelativeRotation().Pitch,
		                                      -Acceleration * (FOVAngleMax / 2) / AccelerationMax,
		                                      EyeLeft->GetRelativeRotation().Roll));
		EyeRight->SetRelativeRotation(FRotator(EyeRight->GetRelativeRotation().Pitch,
		                                       Acceleration * (FOVAngleMax / 2) / AccelerationMax,
		                                       EyeRight->GetRelativeRotation().Roll));
		EyeLeft->FOVAngle = Acceleration * FOVAngleMax / AccelerationMax;
		EyeRight->FOVAngle = Acceleration * FOVAngleMax / AccelerationMax;
	}
	//UE_LOGFMT(LogTemplateCharacter, Log, "{Value}", ("Value" , Acceleration));
}

void ARatasCharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Canceled, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this,
		                                   &ARatasCharacterPlayer::MoveInput);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this,
		                                   &ARatasCharacterPlayer::StopInput);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Canceled, this,
		                                   &ARatasCharacterPlayer::StopInput);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this,
		                                   &ARatasCharacterPlayer::LookInput);

		EnhancedInputComponent->BindAction(TriggerAction, ETriggerEvent::Triggered, this,
		                                   &ARatasCharacterPlayer::TriggerInput);

		EnhancedInputComponent->BindAction(ReloadAction, ETriggerEvent::Triggered, this,
		                                   &ARatasCharacterPlayer::ReloadInput);

		EnhancedInputComponent->BindAction(NextWeaponAction, ETriggerEvent::Started, this, &ARatasCharacterPlayer::NextWeaponInput);
		EnhancedInputComponent->BindAction(PrevWeaponAction, ETriggerEvent::Started, this,
		                                   &ARatasCharacterPlayer::PrevWeaponInput);
		EnhancedInputComponent->BindAction(SelectWeaponAction1, ETriggerEvent::Started, this,
		                                   &ARatasCharacterPlayer::SelectWeaponInput1);
		EnhancedInputComponent->BindAction(SelectWeaponAction2, ETriggerEvent::Started, this,
		                                   &ARatasCharacterPlayer::SelectWeaponInput2);
		EnhancedInputComponent->BindAction(SelectWeaponAction3, ETriggerEvent::Started, this,
		                                   &ARatasCharacterPlayer::SelectWeaponInput3);
		EnhancedInputComponent->BindAction(SelectWeaponAction4, ETriggerEvent::Started, this,
		                                   &ARatasCharacterPlayer::SelectWeaponInput4);
	} else {
		UE_LOG(LogTemplateCharacter, Error,
		       TEXT(
			       "'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."
		       ), *GetNameSafe(this));
	}
}

void ARatasCharacterPlayer::MoveInput(const FInputActionValue& Value) {
	Move(Value.Get<FVector3d>());
	HasEverMoved = true;
}

void ARatasCharacterPlayer::LookInput(const FInputActionValue& Value) {
	Look(Value.Get<FVector3d>());
	//Eyes->SetRelativeRotation(FRotator(Camera->GetRelativeRotation().Pitch, Eyes->GetRelativeRotation().Yaw, Eyes->GetRelativeRotation().Roll));
}

void ARatasCharacterPlayer::TriggerInput() {
	if (WeaponCurrent != nullptr && WeaponCurrent->CheckTrigger()) WeaponCurrent->Trigger();
}

void ARatasCharacterPlayer::NextWeaponInput() {
	if (Arsenal.Num() > 0) {
		int index = Arsenal.Find(WeaponCurrent) + 1;
		if (index >= Arsenal.Num()) index = 0;
		SetWeapon(index);
	}
}

void ARatasCharacterPlayer::PrevWeaponInput() {
	if (Arsenal.Num() > 0) {
		int index = Arsenal.Find(WeaponCurrent) - 1;
		if (index < 0) index = Arsenal.Num() - 1;
		SetWeapon(index);
	}
}

void ARatasCharacterPlayer::SelectWeaponInput1() {
	if (Arsenal.Num() >= 1) SetWeapon(0);
}

void ARatasCharacterPlayer::SelectWeaponInput2() {
	if (Arsenal.Num() >= 2) SetWeapon(1);
}

void ARatasCharacterPlayer::SelectWeaponInput3() {
	if (Arsenal.Num() >= 3) SetWeapon(2);
}

void ARatasCharacterPlayer::SelectWeaponInput4() {
	if (Arsenal.Num() >= 4) SetWeapon(3);
}

void ARatasCharacterPlayer::AddWeapon(ARatasWeapon* Weapon) {
	Arsenal.Add(Weapon);
	SetWeapon(Arsenal.Num() - 1);
}

void ARatasCharacterPlayer::SetWeapon(int index) {
	if (WeaponCurrent != nullptr) {
		WeaponCurrent->SetActorHiddenInGame(true);
		WeaponCurrent->SetActorTickEnabled(false);
		WeaponCurrent->SetActorEnableCollision(false);
	}
	WeaponCurrent = Arsenal[index];
	WeaponCurrent->SetActorHiddenInGame(false);
	WeaponCurrent->SetActorTickEnabled(true);
	WeaponCurrent->SetActorEnableCollision(true);
	CallbackChangeWeapon();
}

void ARatasCharacterPlayer::ReloadInput() {
	if (WeaponCurrent != nullptr && WeaponCurrent->IsA(ARatasWeaponRanged::StaticClass())) {
		Cast<ARatasWeaponRanged>(WeaponCurrent)->Reload();
	}
}

void ARatasCharacterPlayer::StopInput() {
	IsMoving = false;
}

void ARatasCharacterPlayer::GetHit(const float Damage) {
	Acceleration -= Damage;

	if (Acceleration <= 0) {}
}
