// Copyright Raptagon Studios Ltd.

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
	
	virtual void BeginPlay() override;

	void ApplySidewaysForce();

	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	float CurrentThrottle = 0;

public:
	// Set throttle between -1 and +1
	UFUNCTION (BlueprintCallable, Category = "Input")
	void SetThrottle(float Throttle);

	void DriveTrack();
	
	// Max force per track in newtons
	UPROPERTY(BlueprintReadOnly, Category = "Setup")
	float TrackMaxDrivingForce = 40000000; // Assume 40 ton tank and 1g acceleration
};
