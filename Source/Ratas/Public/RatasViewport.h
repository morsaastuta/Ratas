// ©Ratas

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "RatasViewport.generated.h"

class UCanvasPanel;
class UProgressBar;
class UImage;
class UTextBuffer;

UCLASS()
class RATAS_API URatasViewport : public UUserWidget {
	GENERATED_BODY()

	public:
		UPROPERTY(Category=RatasViewport, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		UImage* ImageHelp1;
		UPROPERTY(Category=RatasViewport, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		UImage* ImageHelp2;
		UPROPERTY(Category=RatasViewport, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		UImage* ImageHelp3;

		UFUNCTION(Category=RatasViewport, BlueprintCallable)
		void CallHelp(int Help, bool On);

	protected:
		bool InProcess = false;
		ESlateVisibility TargetVisibility;
		UImage* ActiveImage;
		UPROPERTY(Category=RatasViewport, EditAnywhere, BlueprintReadWrite, meta=(AllowPrivateAccess = "true", ExposeOnSpawn = true))
		float FadeTimerMax;
		float FadeTimer;

		virtual void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;
};
