// Fill out your copyright notice in the Description page of Project Settings.

#include "NormalFoodPelletController.h"


// Sets default values
ANormalFoodPelletController::ANormalFoodPelletController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	

}

// Called when the game starts or when spawned
void ANormalFoodPelletController::BeginPlay()
{
	
	Super::BeginPlay();
	
	normalFoodPelletGenerator();
	
}





void ANormalFoodPelletController::normalFoodPelletSpawnerFunction(int xLocation, int yLocation)
{
	//begins by getting GameInstance so that the location can be added
	UFieldData* FDGI = Cast<UFieldData>(GetGameInstance());

	//generates vector for spawning
	spawnLocation.X = xLocation;
	spawnLocation.Y = yLocation;
	spawnLocation.Z = 50;

	int arrayLocationX = spawnLocation.X / 200 + 7;
	int arrayLocationY = spawnLocation.Y / 200 + 7;
	int arrayIndex = 15 * arrayLocationX + arrayLocationY;

	FString arrayObject = FString(TEXT("n"));
	//FDGI->FieldData[arrayIndex] = arrayObject;

	//creates the parameters for spawning based off of Unreal Documentation guidelines
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = Instigator;
	ANormalFoodPellet* newNormalFoodPellet = GetWorld()->SpawnActor<ANormalFoodPellet>(spawningObject, spawnLocation, FRotator::ZeroRotator, spawnParams);
}

void ANormalFoodPelletController::normalFoodPelletGenerator()
{
	UFieldData* FDGI = Cast<UFieldData>(GetGameInstance());
	for (int i = 0; i < FDGI->FieldData.Num(); i++)
	{
		if (FDGI->FieldData[i] == "u")
		{
			normalFoodPelletSpawnerFunction( (200*(((i-(i%15))/15)-7)),(200*((i%15)-7)));
			
		}
	}
	
}

// Called every frame
void ANormalFoodPelletController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

