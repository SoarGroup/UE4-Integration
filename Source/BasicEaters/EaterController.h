// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Eater.h"
#include "EaterController.generated.h"

UCLASS()
class BASICEATERS_API AEaterController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEaterController();

	int generateX();		//Generates random x coordinate

	int generateY();		//Generates random y coordinate

	FVector spawnLocation;

	void eaterSpawnerFunction(int xLocation, int yLocation);

	UPROPERTY(EditDefaultsOnly, Category = "Spawning Object")
		TSubclassOf<AEater> spawningObject;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
