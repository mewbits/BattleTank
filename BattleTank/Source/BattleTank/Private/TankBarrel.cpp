// Copyright Raptagon Studios Ltd.

#include "TankBarrel.h"
#include "BattleTank.h"
#include "ConstructorHelpers.h"

// Sets default values
UTankBarrel::UTankBarrel()
{
	
}

void UTankBarrel::Elevate(float RelativeSpeed)
{
	//Move the barrel the right amount this frame

	//Given a max elevation speed and the frame time
	RelativeSpeed = FMath::Clamp<float> (RelativeSpeed, -1.f, 1.f);
	
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;
	
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange; 
	
	auto Elevation = FMath::Clamp<float>
	(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	SetRelativeRotation(FRotator(Elevation, 0, 0));
}