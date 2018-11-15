// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "public/Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerPawn = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerPawn)
	{
		// TODO Move towards player

		// Aim Turret Towards Player
		ControlledTank->AimAt(PlayerPawn->GetActorLocation());
	
		// Fire if ready
		ControlledTank->Fire(); // TODO Limit Fireing rate
	}

}

