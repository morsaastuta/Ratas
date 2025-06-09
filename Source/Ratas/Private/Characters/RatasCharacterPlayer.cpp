#include "Characters/RatasCharacterPlayer.h"
#include "EnhancedInputComponent.h"
#include "RatasViewport.h"
#include "RatasWarp.h"
#include "Blueprint/UserWidget.h"
#include "Weapons/RatasWeaponRanged.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UniversalObjectLocators/UniversalObjectLocatorUtils.h"

ARatasCharacterPlayer::ARatasCharacterPlayer() {
	PrimaryActorTick.bCanEverTick = true;

	// Camera
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetCapsuleComponent());
	Camera->SetRelativeLocation(FVector(0.f, 0.f, 0.f));
	Camera->bUsePawnControlRotation = true;
	GetMesh()->SetupAttachment(Camera);

	// Eyes
	EyeLeft = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("EyeLeft"));
	EyeCenter = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("EyeCenter"));
	EyeRight = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("EyeRight"));
	EyeLeft->SetupAttachment(Camera);
	EyeCenter->SetupAttachment(Camera);
	EyeRight->SetupAttachment(Camera);
	EyeLeft->SetRelativeLocation(FVector(-48.f, 0.f, 50.f));
	EyeCenter->SetRelativeLocation(FVector(-48.f, 0.f, 50.f));
	EyeRight->SetRelativeLocation(FVector(-48.f, 0.f, 50.f));
	// Eye blend
	if (IsValid(WidgetReference)) Viewport = CreateWidget(GetWorld(), WidgetReference);

	if (IsValid(Viewport)) {
		Viewport->AddToViewport();
	}

	IsMoving = false;
}

void ARatasCharacterPlayer::BeginPlay() {
	Super::BeginPlay();

	EyeLeft->SetupAttachment(Camera);
	EyeCenter->SetupAttachment(Camera);
	EyeRight->SetupAttachment(Camera);
	GetCharacterMovement()->JumpZVelocity = GetCharacterMovement()->JumpZVelocity * 2;

	// Eye blend
	if (IsValid(WidgetReference)) Viewport = CreateWidget(GetWorld(), WidgetReference);

	if (IsValid(Viewport)) Viewport->AddToViewport();

	Cast<URatasViewport>(Viewport)->CallHelp(1, true);
}

void ARatasCharacterPlayer::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	// Set ACCELERATION MINIMUM depending on IMMORTAL
	if (Immortal) AccelerationMin = 0.1f;
	else AccelerationMin = 0;

	// Prevent ACCELERATION changes while HAS NOT EVER MOVED
	if (HasEverMoved) {
		Acceleration = GetCharacterMovement()->GetLastUpdateVelocity() != FVector(0, 0, 0)
			               ? FMath::Clamp(Acceleration + 0.01f, AccelerationMin, AccelerationMax)
			               : FMath::Clamp(Acceleration - 0.01f, AccelerationMin, AccelerationMax);
	}

	// Calculations
	GetCharacterMovement()->MaxAcceleration = Acceleration * 200.f;
	EyeLeft->SetRelativeRotation(FRotator(0, -Acceleration * FOVAngleMax / AccelerationMax, 0));
	EyeRight->SetRelativeRotation(FRotator(0, Acceleration * FOVAngleMax / AccelerationMax, 0));
	EyeLeft->FOVAngle = Acceleration * FOVAngleMax / AccelerationMax;
	EyeCenter->FOVAngle = Acceleration * FOVAngleMax / AccelerationMax;
	EyeRight->FOVAngle = Acceleration * FOVAngleMax / AccelerationMax;
	//UE_LOGFMT(LogTemplateCharacter, Log, "{Value}", ("Value" , Acceleration));
}

void ARatasCharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent)) {
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Canceled, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARatasCharacterPlayer::MoveInput);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ARatasCharacterPlayer::StopInput);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Canceled, this, &ARatasCharacterPlayer::StopInput);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARatasCharacterPlayer::LookInput);

		EnhancedInputComponent->BindAction(TriggerAction, ETriggerEvent::Started, this, &ARatasCharacterPlayer::TriggerInput);

		EnhancedInputComponent->BindAction(ReloadAction, ETriggerEvent::Started, this, &ARatasCharacterPlayer::ReloadInput);

		EnhancedInputComponent->BindAction(NextWeaponAction, ETriggerEvent::Started, this, &ARatasCharacterPlayer::NextWeaponInput);
		EnhancedInputComponent->BindAction(PrevWeaponAction, ETriggerEvent::Started, this, &ARatasCharacterPlayer::PrevWeaponInput);
		EnhancedInputComponent->BindAction(SelectWeaponAction1, ETriggerEvent::Started, this, &ARatasCharacterPlayer::SelectWeaponInput1);
		EnhancedInputComponent->BindAction(SelectWeaponAction2, ETriggerEvent::Started, this, &ARatasCharacterPlayer::SelectWeaponInput2);
		EnhancedInputComponent->BindAction(SelectWeaponAction3, ETriggerEvent::Started, this, &ARatasCharacterPlayer::SelectWeaponInput3);
		EnhancedInputComponent->BindAction(SelectWeaponAction4, ETriggerEvent::Started, this, &ARatasCharacterPlayer::SelectWeaponInput4);
	} else {
		UE_LOG(LogTemplateCharacter, Error,
		       TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."
		       ), *GetNameSafe(this));
	}
}

void ARatasCharacterPlayer::MoveInput(const FInputActionValue& Value) {
	Move(Value.Get<FVector3d>());
	Cast<URatasViewport>(Viewport)->CallHelp(1, false);
	HasEverMoved = true;
}

void ARatasCharacterPlayer::LookInput(const FInputActionValue& Value) {
	Look(Value.Get<FVector3d>());
	//Eyes->SetRelativeRotation(FRotator(Camera->GetRelativeRotation().Pitch, Eyes->GetRelativeRotation().Yaw, Eyes->GetRelativeRotation().Roll));
}

void ARatasCharacterPlayer::TriggerInput() {
	if (IsValid(WeaponCurrent) && WeaponCurrent->CheckTrigger()) WeaponCurrent->Trigger();
}

void ARatasCharacterPlayer::NextWeaponInput() {
	if (Arsenal.Num() > 0) {
		int Index = Arsenal.Find(WeaponCurrent) + 1;
		if (Index >= Arsenal.Num()) Index = 0;
		SetWeapon(Index);
	}
}

void ARatasCharacterPlayer::PrevWeaponInput() {
	if (Arsenal.Num() > 0) {
		int Index = Arsenal.Find(WeaponCurrent) - 1;
		if (Index < 0) Index = Arsenal.Num() - 1;
		SetWeapon(Index);
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

void ARatasCharacterPlayer::AddWeapon(const ARatasWeapon* Weapon) {
	if (Arsenal.Num() <= 0 || !Arsenal.ContainsByPredicate([&](const UObject* Object) { return Object->GetClass() == Weapon->GetClass(); })) {
		ARatasWeapon* AddedWeapon = Cast<ARatasWeapon>(UE::UniversalObjectLocator::SpawnActorForLocator(this->GetWorld(), Weapon->GetClass(), FName(Weapon->GetName())));

		AddedWeapon->Bounds->UnregisterComponent();
		AddedWeapon->AttachToComponent(Camera, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, false));
		AddedWeapon->Bounds->SetRelativeLocation(FVector(20.f, 20.f, -7.f));

		Cast<URatasViewport>(Viewport)->CallHelp(2, true);
		if (Arsenal.Num() > 0) Cast<URatasViewport>(Viewport)->CallHelp(3, true);

		Arsenal.Add(AddedWeapon);
		SetWeapon(Arsenal.Num() - 1);
	}
}

void ARatasCharacterPlayer::SetWeapon(const int Index) {
	if (Arsenal.IndexOfByKey(WeaponCurrent) != Index) {
		UGameplayStatics::PlaySound2D(this, WeaponGetSound);

		Cast<URatasViewport>(Viewport)->CallHelp(3, true);

		if (IsValid(WeaponCurrent)) {
			WeaponCurrent->SetActorHiddenInGame(true);
			WeaponCurrent->SetActorEnableCollision(false);
		}
		
		WeaponCurrent = Arsenal[Index];
		WeaponCurrent->SetActorHiddenInGame(false);
		WeaponCurrent->SetActorEnableCollision(true);
	}
}

void ARatasCharacterPlayer::ReloadInput() {
	if (IsValid(WeaponCurrent) && WeaponCurrent->IsA(ARatasWeaponRanged::StaticClass())) {
		Cast<ARatasWeaponRanged>(WeaponCurrent)->Reload();
		Cast<URatasViewport>(Viewport)->CallHelp(2, false);
	}
}

void ARatasCharacterPlayer::StopInput() {
	IsMoving = false;
}

void ARatasCharacterPlayer::GetHit(const float Damage) {
	Acceleration = FMath::Clamp(Acceleration - Damage, AccelerationMin, AccelerationMax);
}

void ARatasCharacterPlayer::ContactWarp(ARatasWarp* Warp) {
	CurrentLevel = Warp->CurrentLevel;
	NextLevel = Warp->NextLevel;
	ActivateWarp();
}
