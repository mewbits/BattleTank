// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"


void UTankTurret::Pivot(float RelativeSpeed)
{
	//Move the Turret the right amount this frame

	//Given a max elevation speed and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1.f, 1.f);

	auto PivotChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	auto RawNewPivot = RelativeRotation.Yaw + PivotChange;

	SetRelativeRotation(FRotator(0, RawNewPivot, 0));
}

