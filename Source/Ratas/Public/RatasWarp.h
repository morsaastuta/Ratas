// ©Ratas

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RatasWarp.generated.h"

class UBoxComponent;

UCLASS()
class RATAS_API ARatasWarp : public AActor {
	GENERATED_BODY()

	public:
		ARatasWarp();

		UPROPERTY(Category=RatasWarp, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		UBoxComponent* Bounds;

		UPROPERTY(Category=RatasWarp, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		TSoftObjectPtr<UWorld> CurrentLevel;

		UPROPERTY(Category=RatasWarp, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		TSoftObjectPtr<UWorld> NextLevel;

	protected:
		UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* Comp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
