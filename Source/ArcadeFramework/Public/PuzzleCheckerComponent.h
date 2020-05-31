// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzleSolver.h"
#include "EventComponent.h"
#include "Components/ActorComponent.h"
#include "PuzzleCheckerComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCADEFRAMEWORK_API UPuzzleCheckerComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPuzzleCheckerComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	TArray<APuzzleSolver*> AllPuzzles;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FVector LocationOffset;

	UPROPERTY(BlueprintReadOnly)
	FVector OriginalPosition;

private:
	int CountPuzzle(UEventComponent* Component);

	int PrevSolvedPuzzle = 0;

	TMap<int, bool> SolvedIndex;
};
