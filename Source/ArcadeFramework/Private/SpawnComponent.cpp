// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnComponent.h"

// Sets default values for this component's properties
USpawnComponent::USpawnComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USpawnComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USpawnComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FVector USpawnComponent::NextSpawnPosition()
{
	return FVector(-1745.f, 440, 715);
}

FVector USpawnComponent::NextTeleportPosition()
{
	auto next = FVector(-900.f, 450, 715);
	CurrentTarget = next;
	return next;
}

FVector USpawnComponent::GetCurrentTargetPosition() {
	return CurrentTarget;
}

bool USpawnComponent::IsEnabled()
{
	return Enabled;
}

bool USpawnComponent::SetEnabled(bool bEnabled)
{
	Enabled = bEnabled;
	return Enabled;
}

