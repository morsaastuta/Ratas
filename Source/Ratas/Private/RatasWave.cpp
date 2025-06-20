// ©Ratas

#include "RatasWave.h"
#include "RatasWarp.h"
#include "Characters/RatasCharacterFoe.h"
#include "Weapons/RatasWeapon.h"
#include "Logging/StructuredLog.h"

void ARatasWave::PostInitializeComponents() {
	Super::PostInitializeComponents();
	
	// Hide END WARP
	if (IsValid(EndWarp)) {
		EndWarp->SetActorHiddenInGame(true);
		EndWarp->SetActorTickEnabled(false);
		EndWarp->SetActorEnableCollision(false);
	}
}

void ARatasWave::BeginPlay() {
	Super::BeginPlay();

	// Set children actors in hierarchy as FOES
	TArray<AActor*> AttachedActor;
	GetAttachedActors(AttachedActor);
	for (AActor* Actor : AttachedActor) {
		Foes.Add(Cast<ARatasCharacterFoe>(Actor));
	}

	// Hide assigned FOES
	for (ARatasCharacterFoe* Foe : Foes) {
		if (Foe == nullptr) {
			UE_LOGFMT(LogTemp, Log, "{Value}", ("Value" , "Bro le faltan enemigos a la oleada"));
			break;
		}
		
		if (IsValid(Foe)) {
			Foe->AssignedWave = this;
			Foe->SetActorHiddenInGame(true);
			Foe->SetActorTickEnabled(false);
			Foe->SetActorEnableCollision(false);
		}
	}
	
	// Hide SPAWNED WEAPON
	if (IsValid(SpawnedWeapon)) {
		SpawnedWeapon->SetActorHiddenInGame(true);
		SpawnedWeapon->SetActorTickEnabled(false);
		SpawnedWeapon->SetActorEnableCollision(false);
	}

	// Begin if INITIAL WAVE
	if (InitialWave) Begin();
}

void ARatasWave::Begin() {
	for (ARatasCharacterFoe* Foe : Foes) {
		if (IsValid(Foe)) {
			Foe->SetActorHiddenInGame(false);
			Foe->SetActorTickEnabled(true);
			Foe->SetActorEnableCollision(true);
		}
	}
}

void ARatasWave::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (Deaths >= Foes.Num()) End();
}

void ARatasWave::End() {
	
	if (IsValid(SpawnedWeapon)) {
		SpawnedWeapon->SetActorHiddenInGame(false);
		SpawnedWeapon->SetActorTickEnabled(true);
		SpawnedWeapon->SetActorEnableCollision(true);
	}

	if (IsValid(EndWarp)) {
		EndWarp->SetActorHiddenInGame(false);
		EndWarp->SetActorTickEnabled(true);
		EndWarp->SetActorEnableCollision(true);
	}
	
	if (IsValid(NextWave)) NextWave->Begin();
}
