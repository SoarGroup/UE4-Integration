// Fill out your copyright notice in the Description page of Project Settings.
/*
This class is the holder of all of the data for the game. The UGameInstance class is able to use data across multiple levels.
In our case, we're using it as a singleton class to hold the array representing the playing fields. Every other class (walls, eaters, pellets, etc)
is able to access it to see what's on the playing field.
*/
#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "FieldData.generated.h"

/**
*
*/
UCLASS()
class BASICEATERS_API UFieldData : public UGameInstance
{
	GENERATED_BODY()

public:
	UFieldData(const FObjectInitializer& ObjectInitializer);


	//The following two lines define our array.
	UPROPERTY(EditAnywhere, Category = FieldData)
		TArray<FString> FieldData;

};
