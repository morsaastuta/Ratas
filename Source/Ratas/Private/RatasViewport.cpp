// ©Ratas

#include "RatasViewport.h"
#include "Components/Image.h"
#include "Logging/StructuredLog.h"

void URatasViewport::CallHelp(int Help, bool On) {
	if (!InProcess) {
		switch (Help) {
			case 1:
				if (IsValid(ImageHelp1)) {
					ActiveImage = ImageHelp1;
					if (!On) ImageHelp1 = nullptr;
				} else return;
				break;
			case 2:
				if (IsValid(ImageHelp2)) {
					ActiveImage = ImageHelp2;
					if (!On) ImageHelp2 = nullptr;
				} else return;
				break;
			case 3:
				if (IsValid(ImageHelp3)) {
					ActiveImage = ImageHelp3;
					if (!On) ImageHelp3 = nullptr;
				} else return;
				break;
			default: ;
		}
		
		if (On) {
			FadeTimer = 0;
			TargetVisibility = ESlateVisibility::Visible;
		} else {
			FadeTimer = FadeTimerMax;
			TargetVisibility = ESlateVisibility::Hidden;
		}

		InProcess = true;
	}
}

void URatasViewport::NativeTick(const FGeometry& MyGeometry, float InDeltaTime) {
	Super::NativeTick(MyGeometry, InDeltaTime);
	
	if (InProcess) {
		
		if (TargetVisibility == ESlateVisibility::Visible) {
			FadeTimer = FMath::Clamp(FadeTimer + InDeltaTime, 0, FadeTimerMax);
			if (FadeTimer >= FadeTimerMax) InProcess = false;
		} else if (TargetVisibility == ESlateVisibility::Hidden) {
			FadeTimer = FMath::Clamp(FadeTimer - InDeltaTime, 0, FadeTimerMax);
			if (FadeTimer <= 0) InProcess = false;
		}

		ActiveImage->SetOpacity(FadeTimer / FadeTimerMax);
	}
}
