// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "MonitorMeshComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup="Time Machine", meta=(BlueprintSpawnableComponent))
class ARCADEFRAMEWORK_API UMonitorMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
    
public:
    UFUNCTION(BlueprintCallable, Category="Monitor")
    bool isLaunch();
};
