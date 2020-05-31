// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SpawnComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ARCADEFRAMEWORK_API USpawnComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USpawnComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
private:
	UPROPERTY(EditAnywhere)
	FVector CurrentTarget;

	UPROPERTY(EditAnywhere)
    bool Enabled;
public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Time")
	FVector NextSpawnPosition();

	UFUNCTION(BlueprintCallable, Category = "Time")
	FVector NextTeleportPosition();

	UFUNCTION(BlueprintCallable, Category = "Time")
	FVector GetCurrentTargetPosition();

	UFUNCTION(BlueprintCallable, Category = "Time")
    bool IsEnabled();

	UFUNCTION(BlueprintCallable, Category = "Time")
    bool SetEnabled(bool bEnabled);
};
