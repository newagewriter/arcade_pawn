// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleCheckerComponent.h"
#include "GrabberComponent.h"
#include "ArcadeFramework/SolveEvent.h"
#include "Chaos/ChaosDebugDraw.h"
#include "Windows/LiveCoding/Private/External/LC_Event.h"

#define LOGGER_WARNING false
#define SOLVED_TO_GRAB 1
#define SOLVED_TO_MOVE 2

// Sets default values for this component's properties
UPuzzleCheckerComponent::UPuzzleCheckerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPuzzleCheckerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	auto* Owner = GetOwner();
	OriginalPosition = Owner->GetActorLocation();
	SolvedIndex = TMap<int, bool>();
	int index = 0;
	for (const auto* Puzzle : AllPuzzles)
	{
		SolvedIndex.Add(index++, Puzzle->IsSolved);
	}
}

// Called every frame
void UPuzzleCheckerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	const FVector TargetLocation = OriginalPosition + LocationOffset;
	AActor* Owner = GetOwner();
	auto* Event = Owner->FindComponentByClass<UEventComponent>();
	
	const int SolvedCount = CountPuzzle(Event);
	auto Grabber = GetOwner()->FindComponentByClass<UGrabberComponent>();
	//UE_LOG(LogTemp, Warning, TEXT("%p : Grabber component: "), Grabber)
	
	if (SolvedCount == PrevSolvedPuzzle)
	{
		return;
	}
	if (SolvedCount == AllPuzzles.Num())
	{
		if (Event == nullptr)
		{
			UE_LOG(LogTemp, Error, TEXT("%p : Puzzle owner doesn't contains EventComponent"), *Owner->GetName())
		} else
		{
			//UE_LOG(LogTemp, Warning, TEXT("%s : All puzzle was solved"), *Owner->GetName())
			Event->AllPuzzleSolved.Broadcast();
		}
	}
	else if (SolvedCount == 0)
	{
		Event->NonePuzzleSolved.Broadcast();
	} 
	PrevSolvedPuzzle = SolvedCount;
}

int UPuzzleCheckerComponent::CountPuzzle(UEventComponent* Event)
{
	int SolveCount = 0;
	int index = 0;
	for (APuzzleSolver* Puzzle : AllPuzzles)
	{
		const bool RecentlySolved = SolvedIndex[index];
		if (!Puzzle->IsSolved) {
			if (RecentlySolved)
			{
				Event->OnePuzzleUnsolved.Broadcast(Puzzle);
			}
		} else
		{
			if (!RecentlySolved)
			{
				Event->OnePuzzleSolved.Broadcast(Puzzle);
			}
			SolveCount++;
		}
		SolvedIndex[index] = Puzzle->IsSolved;
		index++;
	}
	return SolveCount;
}

