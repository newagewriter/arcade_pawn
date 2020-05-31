// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzlePawn.h"
#include "GameFramework/Actor.h"

// Sets default values
APuzzlePawn::APuzzlePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APuzzlePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzlePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AActor* PawnOwner = GetOwner();
	UStaticMeshComponent* Component = FindComponentByClass<UStaticMeshComponent>();
	if (Component)
	{
		Component->SetSimulatePhysics(SimulatePhysics);
	} else
	{
		UE_LOG(LogTemp, Error, TEXT("%p : Missing Component"), *PawnOwner->GetName())
    }
}

// Called to bind functionality to input
void APuzzlePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

bool APuzzlePawn::SetSimulatePhysics(const bool bSimulatePhysics)
{
	SimulatePhysics = bSimulatePhysics;
	return SimulatePhysics;
}

