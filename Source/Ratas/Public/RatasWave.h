// ©Ratas

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RatasWave.generated.h"

class ARatasCharacterFoe;
class ARatasWeapon;
class ARatasWarp;

UCLASS()
class RATAS_API ARatasWave : public AActor {
	GENERATED_BODY()

	public:
		UPROPERTY(Category=RatasWave, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		bool InitialWave;

		UPROPERTY(Category=RatasWave, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		TArray<ARatasCharacterFoe*> Foes;

		UPROPERTY(Category=RatasWave, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		ARatasWave* NextWave;

		UPROPERTY(Category=RatasWave, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		ARatasWeapon* SpawnedWeapon;

		UPROPERTY(Category=RatasWave, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true"))
		ARatasWarp* EndWarp;

		int Deaths = 0;

		void Begin();
		void End();

	protected:
		virtual void BeginPlay() override;
		virtual void PostInitializeComponents() override;
		virtual void Tick(float DeltaTime) override;
};
