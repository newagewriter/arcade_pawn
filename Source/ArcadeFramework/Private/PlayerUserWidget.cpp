// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerUserWidget.h"

FString UPlayerUserWidget::FormatTime(float Seconds)
{
    int minutes = 0;
    int sec = Seconds;
    FString result = "";
    if (sec < 0)
    {
        result.Append("-");
        sec = -sec;
    }
    while (sec >= 60)
    {
        sec -= 60;
        minutes++;
    }
    
    if (minutes < 10)
    {
        result.Append("0");
    }
    result.AppendInt(minutes);
    result.Append(":");
    if (sec < 10)
    {
        result.Append("0");
    }
    result.AppendInt(sec);
    return result;
}

float UPlayerUserWidget::GetDeltaTime()
{
    return DeltaTime;
}

float UPlayerUserWidget::AddDeltaSeconds(float Seconds)
{
    DeltaTime += Seconds;
    return DeltaTime;
}
