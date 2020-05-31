// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PressureHandler.h"
#include "SpawnPressureHandler.generated.h"

/**
 * 
 */
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCADEFRAMEWORK_API USpawnPressureHandler : public UPressureHandler
{
	GENERATED_BODY()
public:	
    // Sets default values for this component's properties
    USpawnPressureHandler();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
