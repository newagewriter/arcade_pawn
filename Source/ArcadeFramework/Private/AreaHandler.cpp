// Fill out your copyright notice in the Description page of Project Settings.


#include "AreaHandler.h"
#include "Engine/Player.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

// Sets default values for this component's properties
UAreaHandler::UAreaHandler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAreaHandler::BeginPlay()
{
	Super::BeginPlay();

	if (!PressurePlate) {
		UE_LOG(LogTemp, Error, TEXT("%s missing pressure plate in falling platform"), *GetOwner()->GetName())
	}
	
}


// Called every frame
void UAreaHandler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	auto* Player = GetPlayerInArea();
	if (Player)
	{
		// TODO fix this to check that overlap actor compare to this player
		PlayerController = GetWorld()->GetFirstPlayerController();
		//UE_LOG(LogTemp, Warning, TEXT("%s : player: %s"), *GetOwner()->GetName(), *Player->GetName())
		OnAreaEnter.Broadcast();
		
	}
	else
	{
		PlayerController = nullptr;
		//UE_LOG(LogTemp, Warning, TEXT("%s: No player"), *GetOwner()->GetName())
		OnAreaLeave.Broadcast();
	}
}

APawn* UAreaHandler::GetPlayerInArea() 
{
	TArray<AActor*> OverlappingActors;
	if (!PressurePlate) { return nullptr; }
	PressurePlate->GetOverlappingActors(OUT OverlappingActors);
	APawn* result;
	for (AActor* Actor : OverlappingActors) {
		result = Cast<APawn>(Actor);
		if (result) {
			return result;
		}
	}
	return nullptr;
}

