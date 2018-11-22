// Copyright Raptagon Studios Ltd.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "kismet/GamePlayStatics.h"
#include "Components/ActorComponent.h"
#include "Components/StaticMeshComponent.h"
#include "TankAimingComponent.generated.h"

// creating the enumeration for storing the fireing status
UENUM()
enum class EFiringState : uint8
{
	Reloading,
	Aiming,
	Locked
};

//Forward Declaration
class UTankBarrel; 
class UTankTurret;
class AProjectile;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadOnly, Category = "State")
	EFiringState FiringState = EFiringState::Reloading;

	// Time inbetween Tank Rounds
	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float ReloadTimeInSeconds = 3.f;

	double LastFireTime = 0.f;

public:	

	// Setup the left anf right tank tracks
	UFUNCTION(BlueprintCallable, Category = "Setup")
	void Initialize(UTankBarrel* BarrelToSet, UTankTurret* TurretToSet);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category = "Firing")
	float LaunchSpeed = 4000.f;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = "Firing")
	void Fire();

private:
	// Sets default values for this component's properties
	UTankAimingComponent();
	
	UTankBarrel* Barrel = nullptr;

	UTankTurret* Turret = nullptr;

	void MoveBarrelTowards(FVector AimDirection);

	void MoveTurretTowards(FVector AimDirection);

	
};