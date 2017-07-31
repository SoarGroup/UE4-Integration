// Fill out your copyright notice in the Description page of Project Settings.

#include "BonusFoodPelletController.h"


// Sets default values
ABonusFoodPelletController::ABonusFoodPelletController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int ABonusFoodPelletController::generateX()
{
	int initialX = 0.f;
	initialX = FMath::RandRange(-7, 7);
	// we have a 3000px x 3000px playing field. since we want it to be 15x15, we must divide the field into 255 200px x 200px squares. -7 to 7 allows 15 squares (including 0). this function generates the x coordinate
	initialX = 200 * initialX;
	return initialX;
}

int ABonusFoodPelletController::generateY()
{
	//same as generateX(), but for the y coordinate
	int initialY = 0.f;
	initialY = FMath::RandRange(-7, 7);
	initialY = 200 * initialY;
	return initialY;
}

void ABonusFoodPelletController::bonusFoodPelletSpawnerFunction()
{
	//begins by getting GameInstance so that the location can be added
	UFieldData* FDGI = Cast<UFieldData>(GetGameInstance());

	//generates vector for spawning
	spawnLocation.X = generateX();
	spawnLocation.Y = generateY();
	spawnLocation.Z = 0.f;


	FString arrayLocation = FString(TEXT("b") + FString::FromInt(spawnLocation.X) + FString::FromInt(spawnLocation.Y));
	int b = 0;
	while (b < FDGI->FieldData.Num()) {
		FString tempLocation = FDGI->FieldData[b];
		tempLocation.RemoveAt(0, 1, true);
		FString tempArrayLocation = arrayLocation;
		tempArrayLocation.RemoveAt(0, 1, true);
		if (tempArrayLocation == tempLocation) {
			spawnLocation.X = generateX();
			spawnLocation.Y = generateY();
			FString arrayLocation = FString(TEXT("b") + FString::FromInt(spawnLocation.X) + FString::FromInt(spawnLocation.Y));
			int b = 0;
		}
		else
		{
			b++;
		}
	}

	FDGI->FieldData.Add(arrayLocation);

	//creates the parameters for spawning based off of Unreal Documentation guidelines
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = Instigator;
	ABonusFoodPellet* newBonusFoodPellet = GetWorld()->SpawnActor<ABonusFoodPellet>(spawningObject, spawnLocation, FRotator::ZeroRotator, spawnParams);
}

void ABonusFoodPelletController::bonusFoodPelletGenerator()
{
	int n = FMath::RandRange(4, 6);
	for (int i = 0; i < n; i++) {
		bonusFoodPelletSpawnerFunction();
	}
}



// Called when the game starts or when spawned
void ABonusFoodPelletController::BeginPlay()
{
	Super::BeginPlay();
	bonusFoodPelletGenerator();
	UE_LOG(LogTemp, Log, TEXT("PELLET BOOL"));
}


// Called every frame
void ABonusFoodPelletController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

