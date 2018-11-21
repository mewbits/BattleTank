// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTank;
class UTankTrack;

/**
 * Responsible for Driving the Tank Tracks
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()

public:

	// Setup the left anf right tank tracks
	UFUNCTION(BlueprintCallable, Category = Setup)
	void Initialize(UTankTrack* LeftTrack, UTankTrack* RightTrack);

	//Move the Tank forward on +1 and backward on -1
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendMoveForward(float Throw);

	//Rotate the Tank
	UFUNCTION(BlueprintCallable, Category = Input)
	void IntendTurnRight(float Throw);

	/** path following: request new velocity */
	virtual void RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed) override;

private:
	
	UTankTrack * RightTrack = nullptr;

	UTankTrack * LeftTrack = nullptr;

};
