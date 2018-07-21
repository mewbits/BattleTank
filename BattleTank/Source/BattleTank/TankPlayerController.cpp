// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "BattleTank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not Possesing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller Possesing: %s"), *ControlledTank->GetName());
	}
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshairs();
	
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshairs()
{
	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out Parameter

	
	//If it hits the landscape
	if (GetSightRayHitLocation(HitLocation)) // side effect, ray trace
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit Location: %s"), *HitLocation.ToString());
		//TODO: Tell controlled pawn to aim at this point
	}


}

//Get world location of linetrace through crosshairs, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	// Find the Crosshair Position
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	
	// "De-project" the screen position of the crosshair to the world direction
	// Line-trace along that direction, and see what we hit (up to max range)
	return true;
}