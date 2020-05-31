// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PuzzleSolver.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "TrampolineComponent.h"
#include "PressureHandler.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPressureRequest);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPressureRelease);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCADEFRAMEWORK_API UPressureHandler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPressureHandler();

protected:
	UPROPERTY(EditAnywhere)
    ATriggerVolume* PressurePlate;
	
	// Called when the game starts
	virtual void BeginPlay() override;

	virtual AActor* GetFirstActor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(BlueprintAssignable)
	FOnPressureRequest OnPressureRequest;

	UPROPERTY(BlueprintAssignable)
	FOnPressureRelease OnPressureRelease;

private:
	UPROPERTY(EditAnywhere)
	float TriggerMass = 10.f;

	float GetTotalMassOfActorsOnPlate();

	APuzzleSolver* GetPuzzleSolver();
	
public:
	UPROPERTY(BlueprintReadOnly)
	AActor* FirstActor;
};
