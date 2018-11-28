// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "ConstructorHelpers.h"


// Sets default values
UTankTurret::UTankTurret()
{
	
}

void UTankTurret::Pivot(float RelativeSpeed)
{
	//Move the Turret the right amount this frame

	//Given a max elevation speed and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);

	auto PivotChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	auto Pivot = RelativeRotation.Yaw + PivotChange;

	SetRelativeRotation(FRotator(0, Pivot, 0));
}

