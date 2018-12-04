// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// +1 is the maximum upward movement speed and -1 is the maximum downward movement speed
	void Pivot(float RelativeSpeed);
	
private:

	// Sets default values for this Static Mesh Component's properties
	UTankTurret();
	
	// Maximum degrees the Turret can move per second
	UPROPERTY(EditDefaultsOnly, Category = "Setup")
		float MaxDegreesPerSecond = 20.f;
};
