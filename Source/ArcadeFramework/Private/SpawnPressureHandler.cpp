// Fill out your copyright notice in the Description page of Project Settings.


#include "SpawnPressureHandler.h"
#include "GameFramework/Actor.h"

USpawnPressureHandler::USpawnPressureHandler()
{
    
}

void USpawnPressureHandler::TickComponent(float DeltaTime, ELevelTick TickType,
    FActorComponentTickFunction* ThisTickFunction)
{
    if (PressurePlate)
    {
        AActor* Actor = GetFirstActor();
        if (Actor)
        {
            UE_LOG(LogTemp, Error, TEXT("%s found actor"), *Actor->GetName())
            OnPressureRequest.Broadcast();
        } else
        {
            OnPressureRelease.Broadcast();
        }
    }
}
