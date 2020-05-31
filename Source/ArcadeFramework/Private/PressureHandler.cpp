// Fill out your copyright notice in the Description page of Project Settings.


#include "PressureHandler.h"
#include "GameFramework/Actor.h"
#include "TrampolineComponent.h"
#include "Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
UPressureHandler::UPressureHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPressureHandler::BeginPlay()
{
	Super::BeginPlay();

	if (!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate in falling platform"), *GetOwner()->GetName())
	}
	
}


// Called every frame
void UPressureHandler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	APuzzleSolver* Solver = GetPuzzleSolver();
	if (Solver)
	{
		//UE_LOG(LogTemp, Error, TEXT("%s ok"), *Solver->GetName())
		Solver->IsSolved = GetTotalMassOfActorsOnPlate() > TriggerMass;
		if (Solver->IsSolved) {
			OnPressureRequest.Broadcast();
		}
		else
		{
			OnPressureRelease.Broadcast();
		}
	}
	FirstActor = this->GetFirstActor();
	if (FirstActor)
	{
		OnPressureRequest.Broadcast();
	}
	else
	{
		OnPressureRelease.Broadcast();
	}
}

float UPressureHandler::GetTotalMassOfActorsOnPlate()
{
	float TotalMass = 0.f;
	TArray<AActor*> OverlappingActors;
	if (!PressurePlate) { return TotalMass; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	for (const auto* Actor : OverlappingActors) {
		auto* Component = Actor->FindComponentByClass<UPrimitiveComponent>();
		if (Component->Mobility == EComponentMobility::Type::Movable) {
			TotalMass += Actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		}
	}
	return TotalMass;
}

AActor* UPressureHandler::GetFirstActor() {
	TArray<AActor*> OverlappingActors;
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	for (AActor* Actor : OverlappingActors) {
		return Actor;
	}
	return nullptr;
}

APuzzleSolver* UPressureHandler::GetPuzzleSolver()
{
	return Cast<APuzzleSolver>(GetOwner());
}



