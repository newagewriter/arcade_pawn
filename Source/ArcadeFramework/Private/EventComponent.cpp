// Fill out your copyright notice in the Description page of Project Settings.


#include "EventComponent.h"


// Sets default values for this component's properties
UEventComponent::UEventComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

AActor* UEventComponent::GetActorOwner()
{
	return GetOwner();
}




