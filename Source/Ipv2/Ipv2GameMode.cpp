// Copyright Epic Games, Inc. All Rights Reserved.

#include "Ipv2GameMode.h"
#include "Ipv2Character.h"
#include "UObject/ConstructorHelpers.h"

AIpv2GameMode::AIpv2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
