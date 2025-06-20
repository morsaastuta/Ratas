// ©Ratas

#include "RatasWarp.h"

#include "Characters/RatasCharacterPlayer.h"
#include "Components/BoxComponent.h"

ARatasWarp::ARatasWarp() {
	Bounds = CreateDefaultSubobject<UBoxComponent>(TEXT("Bounds"));
	Bounds->OnComponentBeginOverlap.AddDynamic(this, &ARatasWarp::OnBeginOverlap);
}

void ARatasWarp::OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	if (OtherActor->IsA(ARatasCharacterPlayer::StaticClass())) {
		Cast<ARatasCharacterPlayer>(OtherActor)->ContactWarp(this);
	}
}
