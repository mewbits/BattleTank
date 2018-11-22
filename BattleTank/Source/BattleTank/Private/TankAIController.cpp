// Copyright Raptagon Studios Ltd.

#include "TankAIController.h"
#include "public/Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());

	if (PlayerTank)
	{
		// Move towards player
		MoveToActor(PlayerTank, AcceptanceRadius, true, true, false, 0, true);


		// Aim Turret Towards Player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
	
		// Fire if ready
		ControlledTank->Fire(); // TODO Limit Fireing rate
	}

}

