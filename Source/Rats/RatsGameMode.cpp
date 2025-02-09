// Copyright Epic Games, Inc. All Rights Reserved.

#include "RatsGameMode.h"
#include "UObject/ConstructorHelpers.h"

ARatsGameMode::ARatsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
