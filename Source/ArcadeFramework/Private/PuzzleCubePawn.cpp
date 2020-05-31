// Fill out your copyright notice in the Description page of Project Settings.


#include "PuzzleCubePawn.h"

// Sets default values
APuzzleCubePawn::APuzzleCubePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APuzzleCubePawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APuzzleCubePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APuzzleCubePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

