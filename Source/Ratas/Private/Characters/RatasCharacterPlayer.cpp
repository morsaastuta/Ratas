#include "Characters/RatasCharacterPlayer.h"
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
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

