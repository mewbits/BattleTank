// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"
#include "ConstructorHelpers.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"


// Sets default values
UTankTrack::UTankTrack()
{
	PrimaryComponentTick.bCanEverTick = true;
	//Mesh
	static ConstructorHelpers::FObjectFinder<UStaticMesh> StaticMeshTrack(TEXT("StaticMesh'/Game/Meshes/Static/Tank/SM_TankTrack.SM_TankTrack'"));
	if (StaticMeshTrack.Object)
	SetStaticMesh(StaticMeshTrack.Object);
}

void UTankTrack::BeginPlay()
{
	Super::BeginPlay();
	OnComponentHit.AddDynamic(this, &UTankTrack::OnHit);
}


void UTankTrack::TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto SlippageSpeed = FVector::DotProduct(GetRightVector(), GetComponentVelocity());
	
	//Work-out the required acceleration this frame to correct
	auto CorrectionAcceleration = -SlippageSpeed / DeltaTime * GetRightVector();
	
	//Calculate and apply sideways force (f = m * a)
	auto TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	auto CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration)/ 2;
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrack::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("TankMessage:Track Hit Ground"))
}

void UTankTrack::SetThrottle(float Throttle)
{
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast <UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}