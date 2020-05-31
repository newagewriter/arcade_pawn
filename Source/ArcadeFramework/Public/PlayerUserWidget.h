// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "String/ParseLines.h"

#include "PlayerUserWidget.generated.h"

/**
 * 
 */
UCLASS(Abstract, editinlinenew, BlueprintType, Blueprintable, meta = (DontUseGenericSpawnObject = "True", DisableNativeTick))
class ARCADEFRAMEWORK_API UPlayerUserWidget : public UUserWidget
{
	GENERATED_BODY()
private:
	float DeltaTime = 0.0f;
public:
	UFUNCTION(BlueprintCallable, Category="Player UI")
	static FString FormatTime(float Seconds);

	UFUNCTION(BluePrintCallable, Category = "Player UI")
	float GetDeltaTime();

	UFUNCTION(BluePrintCallable, Category = "Player UI")
	float AddDeltaSeconds(float seconds);
};
