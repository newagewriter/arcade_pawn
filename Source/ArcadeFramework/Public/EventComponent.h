// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EventComponent.generated.h"


class APuzzleSolver;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOnePuzzleSolved, APuzzleSolver*, PuzzleSolver);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnOnePuzzleUnsolved, APuzzleSolver*, PuzzleSolver);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnAllPuzzleSolved);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnNonePuzzleSolved);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCADEFRAMEWORK_API UEventComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	
	// Sets default values for this component's properties
	UEventComponent();
 
	UPROPERTY(BlueprintAssignable)
    FOnOnePuzzleSolved OnePuzzleSolved;

	UPROPERTY(BlueprintAssignable)
    FOnOnePuzzleUnsolved OnePuzzleUnsolved;

	UPROPERTY(BlueprintAssignable)
    FOnAllPuzzleSolved AllPuzzleSolved;

	UPROPERTY(BlueprintAssignable)
    FOnNonePuzzleSolved NonePuzzleSolved;

	UFUNCTION(BlueprintCallable, Category = "Parent")
	AActor* GetActorOwner();
		
};
