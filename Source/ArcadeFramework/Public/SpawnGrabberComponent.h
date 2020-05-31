// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "SpawnGrabberComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCADEFRAMEWORK_API USpawnGrabberComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnGrabberComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

private:
	AActor* GrabbedActor;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Ray-cast and grab what's in reach
	UFUNCTION(BlueprintCallable, Category="Grabber")
    void Grab(AActor* ActorToGrab);

	// Called when grab is released
	UFUNCTION(BlueprintCallable, Category="Grabber")
    void Release();

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
};
