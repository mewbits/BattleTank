// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank Track is used to set the maximum driving force and apply forces to the tank.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	// Sets default values for this Static Mesh Component's properties
	UTankTrack();

public:
	// Set throttle between -1 and +1
	UFUNCTION (BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
	// Max force per track in newtons
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float TrackMaxDrivingForce = 40000000; // Assume 40 ton tank and 1g acceleration
};
