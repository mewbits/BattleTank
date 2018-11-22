// Copyright Raptagon Studios Ltd.

#include "TankAIController.h"
#include "TankAimingComponent.h"

//depends on Movement Component via pathfinding system

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	

	if (!PlayerTank) { return; }
	// Move towards player
	MoveToActor(PlayerTank, AcceptanceRadius, true, true, false, 0, true);		

	auto AimingComponent = GetPawn()->FindComponentByClass<UTankAimingComponent>();
	if (!AimingComponent) { return; }
	// Aim Turret Towards Player
	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	// Fire if ready
	AimingComponent->Fire();

}

