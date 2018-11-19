// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "ConstructorHelpers.h"


// Sets default values
UTankTrack::UTankTrack()
{
	//Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshTrack(TEXT("StaticMesh'/Game/Meshes/Static/Tank/SM_TankTrack.SM_TankTrack'"));
	if (StaticMeshTrack.Object)
	SetStaticMesh(StaticMeshTrack.Object);
}

void UTankTrack::SetThrottle(float Throttle)
{
	//auto Time = GetWorld()->GetTimeSeconds();
	auto Name = GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s throttle: %f!"), *Name, Throttle);

	//TODO clamp actual throttle value so player can't over-drive
	

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast <UPrimitiveComponent>(GetOwner()->GetRootComponent());

	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}