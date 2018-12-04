// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

// The Barrel of the Tank
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// +1 is the maximum upward movement speed and -1 is the maximum downward movement speed
	void Elevate(float RelativeSpeed);

private:
	// Sets default values for this Static Mesh Component's properties
	UTankBarrel();
	
	// Maximum degrees the barrel can move per second
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxDegreesPerSecond = 10.f;

	// Minimim elevation in degrees the barrel can move to.
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MinElevationDegrees = 0.f; 

	// Maximum elevation in degrees the barrel can move to.
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
	float MaxElevationDegrees = 20.f;
};
