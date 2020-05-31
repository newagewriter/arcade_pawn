// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeTravelOptionsComponent.h"

// Sets default values for this component's properties
UTimeTravelOptionsComponent::UTimeTravelOptionsComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTimeTravelOptionsComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTimeTravelOptionsComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FString UTimeTravelOptionsComponent::GetChangeOptionString() const
{
	return Changes;
}

FString UTimeTravelOptionsComponent::GetTimeShiftOptionsString() const
{
	FString Result = "time=";
	Result.AppendInt(TimeShift);
	return Result;
}

