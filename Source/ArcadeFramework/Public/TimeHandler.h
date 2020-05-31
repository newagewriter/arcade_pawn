// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzleSolver.h"
#include "Components/ActorComponent.h"
#include "TimeHandler.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnTimeTrigger);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCADEFRAMEWORK_API UTimeHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTimeHandler();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float TriggerTimeInSeconds;

	float ActualTime = 0.f;
	APuzzleSolver* PuzzleSolver = nullptr;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	float GetActualTime(float DeltaTime);
	
	UPROPERTY(BlueprintAssignable)
    FOnTimeTrigger OnTimeTrigger;

	UFUNCTION(BlueprintCallable, Category = "Time")
	bool SetupStartTime(float StartTime);
};
