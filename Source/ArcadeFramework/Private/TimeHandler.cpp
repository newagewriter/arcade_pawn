// Fill out your copyright notice in the Description page of Project Settings.


#include "TimeHandler.h"

// Sets default values for this component's properties
UTimeHandler::UTimeHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTimeHandler::BeginPlay()
{
	Super::BeginPlay();

	// ...
	PuzzleSolver = Cast<APuzzleSolver>(GetOwner());
	if (!PuzzleSolver)
	{
		UE_LOG(LogTemp, Error, TEXT("%s owner must be a Puzzle Solver type"), *GetOwner()->GetName())
	}
}


// Called every frame
void UTimeHandler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
	if (PuzzleSolver)
	{
		const float time = GetActualTime(DeltaTime);
		PuzzleSolver->IsSolved = time >= TriggerTimeInSeconds;
		if (PuzzleSolver->IsSolved)
		{
			OnTimeTrigger.Broadcast();
		}
	}
}

float UTimeHandler::GetActualTime(float DeltaTime)
{
	ActualTime += DeltaTime;
	return ActualTime;
}

bool UTimeHandler::SetupStartTime(float StartTime)
{
	ActualTime = StartTime;
	return true;
}

