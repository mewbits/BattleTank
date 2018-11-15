// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Engine/World.h"
#include "TankPlayerController.generated.h"

//Forward Declaration
class ATank;


/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

private:
	ATank* GetControlledTank() const;

	//Move Barrel to aim towards where aiming crosshairs intersects the world
	void AimTowardsCrosshairs();

	//Return an OUT parameter, True if hit landscape
	bool GetSightRayHitLocation(FVector& HitLocation) const;

	UPROPERTY (EditDefaultsOnly)
		float CrossHairXLocation = 0.5f;
	UPROPERTY (EditDefaultsOnly)
		float CrossHairYLocation = 0.33333f;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.f;
	
	bool GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
