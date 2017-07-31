// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FieldData.h"
#include "Wall.h"
#include "WallController.generated.h"
using namespace std;

UCLASS()
class BASICEATERS_API AWallController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AWallController();

	int generateX();		//Generates random x coordinate

	int generateY();		//Generates random y coordinate

	FVector spawnLocation;	//location of wall's spawn

	void wallSpawnerFunction(int xLocation, int yLocation); //this function spawns the walls based on a desired location. it is referenced by generateInXDirection() and generateInYDirection()

	void generateInXDirection(int number);	//generates a certain number of walls in x direction based on the number parameter

	void generateInYDirection(int number);	//generates a certain number of walls in y direction based on the number parameter

	void wallGenerator();	// this function is the main generator that is referenced in BeginPlay(). it calls generateInXDirection() and generateInYDirection() a random number of times to ensure a random placement of walls is made


							//the following two lines allow for the walls to be spawned. this is referenced in wallSpawnerFunction() to allow it to place a wall at a desired vector
	UPROPERTY(EditDefaultsOnly, Category = "Spawning Object")
		TSubclassOf<AWall> spawningObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;



};
