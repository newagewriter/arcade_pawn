// Fill out your copyright notice in the Description page of Project Settings.


#include "OriginalComponent.h"

// Sets default values for this component's properties
UOriginalComponent::UOriginalComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOriginalComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	AActor* OriginalOwner = GetOwner();
	if (OriginalOwner)
	{
		const FVector Location = OriginalOwner->GetActorLocation();
		OriginalWorldPosition = new FVector(Location);
	}
}


// Called every frame
void UOriginalComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	
}

FVector UOriginalComponent::GetOriginalLocation() const
{
	return FVector(OriginalWorldPosition->X, OriginalWorldPosition->Y, OriginalWorldPosition->Z);
}

