// Fill out your copyright notice in the Description page of Project Settings.

#include "WallController.h"
#include "FieldData.h"


// Sets default values
AWallController::AWallController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


int AWallController::generateX()
{
	int initialX = 0.f;
	initialX = FMath::RandRange(0, FieldData::get().grid_size - 1);
	return initialX;
}

int AWallController::generateY()
{
	//same as generateX(), but for the y coordinate
	int initialY = 0.f;
	initialY = FMath::RandRange(0, FieldData::get().grid_size - 1);
	return initialY;
}


void AWallController::wallSpawnerFunction(int arrayLocationX, int arrayLocationY)
{
	//begins by getting GameInstance so that the location can be added
  FieldData &fieldData = FieldData::get();

	//adds the location of the wall to a global array found in GameInstance in the format of "[object identifier][xlocation][ylocation]". Z location is superfluous because it is constant for all actors
	//"w" identifier is for wall, "e" for eater, "n" for normal food pellet, "b" for bonus food pellet
	
	//FString arrayLocation = FString(TEXT("w") + FString::FromInt(xLocation) + FString::FromInt(yLocation));
	//FDGI->FieldData.Add(arrayLocation);

  fieldData.cells[arrayLocationX][arrayLocationY].item = FieldData::Item::WALL;

	//creates the parameters for spawning based off of Unreal Documentation guidelines
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = Instigator;
  FVector spawnLocation(arrayLocationX * fieldData.render_scaling_factor, arrayLocationY * fieldData.render_scaling_factor, 0);
	AWall* newWall = GetWorld()->SpawnActor<AWall>(spawningObject, spawnLocation, FRotator::ZeroRotator, spawnParams);

  fieldData.cells[arrayLocationX][arrayLocationY].set_object(newWall);
}

void AWallController::generateInXDirection(int number) {
	//creates starting location for wall
	int initialXLocation = generateX();
	int initialYLocation = generateY();

	//creates the wall
	wallSpawnerFunction(initialXLocation, initialYLocation);

	//chooses which direction along x axis to move
	int direction = FMath::RandRange(1, 2);

	//loops wallSpawner function based on location, direction, and number of desired wall actors
	for (int i = 0; i < number; i++)
	{
		if (initialXLocation == -1 || initialXLocation == FieldData::get().grid_size)
      break;

    wallSpawnerFunction(initialXLocation, initialYLocation);

    initialXLocation += direction == 1 ? -1 : 1;
	}




}

void AWallController::generateInYDirection(int number) {
	//see generateInXDirection for documentation
	int initialXLocation = generateX();
	int initialYLocation = generateY();

	number = number - 1;

	wallSpawnerFunction(initialXLocation, initialYLocation);
	int direction = FMath::RandRange(1, 2);

	for (int i = 0; i < number; i++)
	{
		if (initialYLocation == -1 || initialYLocation == FieldData::get().grid_size)
      break;

    wallSpawnerFunction(initialXLocation, initialYLocation);

    initialYLocation += direction == 1 ? -1 : 1;
	}
}

void AWallController::wallGenerator() {
	//creates a random number of walls in the x direction between 4 and 8
	int n = FMath::RandRange(4, 8);
	for (int i = 0; i < n; i++)
	{
		generateInXDirection(FMath::RandRange(2, 6));
		//generates between 2 and 6 walls in a row
	}
	n = FMath::RandRange(4, 8);
	for (int i = 0; i < n; i++)
	{
		generateInYDirection(FMath::RandRange(2, 6));
	}

}


// Called when the game starts or when spawned
void AWallController::BeginPlay()
{
	Super::BeginPlay();


	wallGenerator();
	UE_LOG(LogTemp, Log, TEXT("WALL"));


}

// Called every frame
void AWallController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

