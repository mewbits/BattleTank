// Copyright Raptagon Studios Ltd.

#include "Tank.h"
#include "TankBarrel.h"
#include "TankAimingComponent.h"

//Forward Declarations
class UTankTurret;
class AProjectile;

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}
