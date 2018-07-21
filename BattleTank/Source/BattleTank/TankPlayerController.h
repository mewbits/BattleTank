// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "public/Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

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
};
