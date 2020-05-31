// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnGrabberComponent.h"

#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"

// Sets default values for this component's properties
USpawnGrabberComponent::USpawnGrabberComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnGrabberComponent::BeginPlay()
{
	Super::BeginPlay();

	/// Look for attached Physics Handle	
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle)
	{
		// Physisc Handle was found
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("%s missing physics handle component"), *GetOwner()->GetName())
    }
	
}


// Called every frame
void USpawnGrabberComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void USpawnGrabberComponent::Grab(AActor* ActorToGrab)
{
	UPrimitiveComponent* Component = ActorToGrab->FindComponentByClass<UPrimitiveComponent>();
	if (Component) {
		GrabbedActor = ActorToGrab;
		PhysicsHandle->GrabComponentAtLocation(
            Component,
            NAME_None, // no bones needed
            ActorToGrab->GetActorLocation()
        );
	}
}

void USpawnGrabberComponent::Release() {
	if (!PhysicsHandle) { return; }
	PhysicsHandle->ReleaseComponent();
}
