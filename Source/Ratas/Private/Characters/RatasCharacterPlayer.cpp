#include "Characters/RatasCharacterPlayer.h"
#include "EnhancedInputComponent.h"
#include "Blueprint/UserWidget.h"
#include "Components/CapsuleComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Logging/StructuredLog.h"


// Sets default values
ARatasCharacterPlayer::ARatasCharacterPlayer()
{
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
	if (IsValid(WidgetReference))
	{
		EyeBlend = CreateWidget(GetWorld(), WidgetReference);
	}
	
	if (IsValid(EyeBlend))
	{
		EyeBlend->AddToViewport();
	}

	IsMoving = false;
}

void ARatasCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARatasCharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Acceleration = IsMoving ? FMath::Clamp(Acceleration + 0.01f, 1.f, 4.f) : FMath::Clamp(Acceleration - 0.01f, 1.f, 4.f);

	GetCharacterMovement()->MaxAcceleration = Acceleration * 1000.f;

	
	//UE_LOGFMT(LogTemplateCharacter, Log, "{Value}", ("Value" , Acceleration));


	
}

void ARatasCharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Canceled, this, &ACharacter::StopJumping);

		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARatasCharacterPlayer::MoveInput);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Completed, this, &ARatasCharacterPlayer::StopInput);
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Canceled, this, &ARatasCharacterPlayer::StopInput);

		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARatasCharacterPlayer::LookInput);
		
		EnhancedInputComponent->BindAction(ActAction, ETriggerEvent::Triggered, this, &ARatasCharacterPlayer::ActInput);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}
}

void ARatasCharacterPlayer::MoveInput(const FInputActionValue& Value)
{
	//UE_LOGFMT(LogTemplateCharacter, Log, "Hello {Value} World", ("Value" , Value.ToString()));

	IsMoving = true;
	
	Move(Value.Get<FVector2d>());
}

void ARatasCharacterPlayer::LookInput(const FInputActionValue& Value)
{
	//printf("LUKIN");

	Look(Value.Get<FVector2d>());
}

void ARatasCharacterPlayer::ActInput(const FInputActionValue& Value)
{
	//printf("ACTIN");

	if (Value.Get<bool>()) Act();
}

void ARatasCharacterPlayer::StopInput(const FInputActionValue& _)
{
	
	//UE_LOGFMT(LogTemplateCharacter, Log, "Stoppeao");
	IsMoving = false;
}

