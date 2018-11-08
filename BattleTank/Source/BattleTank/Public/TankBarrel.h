// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

// The Barrel of the Tank
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// +1 is the maximum upward movement speed and -1 is the maximm downward movement speed
	void Elevate(float RelativeSpeed);

private:
	
	// Maximum degrees the barrel can move per second
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 5.f;

	// Minimim elevation in degrees the barrel can move to.
	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegrees = 0.f; 

	// Maximum elevation in degrees the barrel can move to.
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegrees = 20.f;
	
	
};
