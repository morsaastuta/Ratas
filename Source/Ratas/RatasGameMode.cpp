// Copyright Epic Games, Inc. All Rights Reserved.

#include "RatasGameMode.h"
#include "RatasCharacter.h"
#include "UObject/ConstructorHelpers.h"

ARatasGameMode::ARatasGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
