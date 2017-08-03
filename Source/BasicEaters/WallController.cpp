// Fill out your copyright notice in the Description page of Project Settings.

#include "WallController.h"


// Sets default values
AWallController::AWallController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}


int AWallController::generateX()
{
	int initialX = 0.f;
	initialX = FMath::RandRange(-7, 7);
	// we have a 3000px x 3000px playing field. since we want it to be 15x15, we must divide the field into 255 200px x 200px squares. -7 to 7 allows 15 squares (including 0). this function generates the x coordinate
	initialX = 200 * initialX;
	return initialX;
}

int AWallController::generateY()
{
	//same as generateX(), but for the y coordinate
	int initialY = 0.f;
	initialY = FMath::RandRange(-7, 7);
	initialY = 200 * initialY;
	return initialY;
}


void AWallController::wallSpawnerFunction(int xLocation, int yLocation)
{
	//begins by getting GameInstance so that the location can be added
	UFieldData* FDGI = Cast<UFieldData>(GetGameInstance());

	//generates vector for spawning
	spawnLocation.X = xLocation;
	spawnLocation.Y = yLocation;
	spawnLocation.Z = 0.f;

	//adds the location of the wall to a global array found in GameInstance in the format of "[object identifier][xlocation][ylocation]". Z location is superfluous because it is constant for all actors
	//"w" identifier is for wall, "e" for eater, "n" for normal food pellet, "b" for bonus food pellet
	
	//FString arrayLocation = FString(TEXT("w") + FString::FromInt(xLocation) + FString::FromInt(yLocation));
	//FDGI->FieldData.Add(arrayLocation);

	int arrayLocationX = spawnLocation.X / 200 + 7;
	int arrayLocationY = spawnLocation.Y / 200 + 7;
	int arrayIndex = 15 * arrayLocationX + arrayLocationY;

	while (FDGI->FieldData[arrayIndex] != "u") {
		
		spawnLocation.X = generateX();
		spawnLocation.Y = generateY();
		arrayLocationX = spawnLocation.X / 200 + 7;
		arrayLocationY = spawnLocation.Y / 200 + 7;
		arrayIndex = 15 * arrayLocationX + arrayLocationY;
	}
	FString arrayObject = FString(TEXT("w"));
	FDGI->FieldData[arrayIndex] = arrayObject;

	//creates the parameters for spawning based off of Unreal Documentation guidelines
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = Instigator;
	AWall* newWall = GetWorld()->SpawnActor<AWall>(spawningObject, spawnLocation, FRotator::ZeroRotator, spawnParams);
}

void AWallController::generateInXDirection(int number) {
	//creates starting location for wall
	int initialXLocation = generateX();
	int initialYLocation = generateY();

	//ensures correct number in a row
	number = number - 1;

	//creates the wall
	wallSpawnerFunction(initialXLocation, initialYLocation);

	//chooses which direction along x axis to move
	int direction = FMath::RandRange(1, 2);

	//loops wallSpawner function based on location, direction, and number of desired wall actors
	for (int i = 0; i < number; i++)
	{
		if (initialXLocation == 1400 || initialXLocation == -1400)
		{
			direction = 0;
			//if the wall is at the edge of the playing field, stop it from creating more
		}

		if (direction == 1)
		{
			initialXLocation = initialXLocation - 200;
			wallSpawnerFunction(initialXLocation, initialYLocation);
		}
		else if (direction == 2)
		{
			initialXLocation = initialXLocation + 200;
			wallSpawnerFunction(initialXLocation, initialYLocation);
		}
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
		if (initialYLocation == 1400 || initialYLocation == -1400)
		{
			direction = 0;
		}

		if (direction == 1)
		{
			initialYLocation = initialYLocation - 200;
			wallSpawnerFunction(initialXLocation, initialYLocation);
		}
		else if (direction == 2)
		{
			initialYLocation = initialYLocation + 200;
			wallSpawnerFunction(initialXLocation, initialYLocation);
		}
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

	//retrieves GameInstance to access array
	UFieldData* FDGI = Cast<UFieldData>(GetGameInstance());

	wallGenerator();
	UE_LOG(LogTemp, Log, TEXT("WALL"));


}

// Called every frame
void AWallController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

