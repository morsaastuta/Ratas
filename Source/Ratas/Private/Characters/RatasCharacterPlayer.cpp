#include "Characters/RatasCharacterPlayer.h"
#include "EnhancedInputComponent.h"
#include "Components/CapsuleComponent.h"


// Sets default values
ARatasCharacterPlayer::ARatasCharacterPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a CameraComponent	
	FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCameraComponent->SetupAttachment(GetCapsuleComponent());
	FirstPersonCameraComponent->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera
	FirstPersonCameraComponent->bUsePawnControlRotation = true;


	Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	

}

// Called when the game starts or when spawned
void ARatasCharacterPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARatasCharacterPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARatasCharacterPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{	
	// Set up action bindings
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		// Jumping
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACharacter::Jump);
		EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACharacter::StopJumping);

		// Moving
		EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ARatasCharacterPlayer::MoveInput);

		// Looking
		EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ARatasCharacterPlayer::LookInput);

		// Acting
		EnhancedInputComponent->BindAction(ActAction, ETriggerEvent::Triggered, this, &ARatasCharacterPlayer::ActInput);
	}
	else
	{
		UE_LOG(LogTemplateCharacter, Error, TEXT("'%s' Failed to find an Enhanced Input Component! This template is built to use the Enhanced Input system. If you intend to use the legacy system, then you will need to update this C++ file."), *GetNameSafe(this));
	}

	

	// input is a Vector2D
	//FVector2D LookAxisVector = Value.Get<FVector2D>();

	//if (Controller != nullptr)
	//{
	////	AddControllerPitchInput(LookAxisVector.Y);
	//}
}

void ARatasCharacterPlayer::MoveInput(const FInputActionValue& Value)
{
	Move(Value.Get<FVector2d>());
}

void ARatasCharacterPlayer::LookInput(const FInputActionValue& Value)
{
	Look(Value.Get<FVector2d>());
}

void ARatasCharacterPlayer::ActInput(const FInputActionValue& Value)
{
	if (Value.Get<bool>()) Act();
}

void ARatasCharacterPlayer::Move(const FVector2d& Value)
{

}

void ARatasCharacterPlayer::Look(const FVector2d& Value)
{

}

void ARatasCharacterPlayer::Act()
{

}

