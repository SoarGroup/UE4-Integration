// Fill out your copyright notice in the Description page of Project Settings.

#include "EaterController.h"
#include "FieldData.h"


// Sets default values
AEaterController::AEaterController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int AEaterController::generateX()
{
	int initialX = 0.f;
	initialX = FMath::RandRange(0, FieldData::get().grid_size - 1);
	return initialX;
}

int AEaterController::generateY()
{
	int initialY = 0.f;
	initialY = FMath::RandRange(0, FieldData::get().grid_size - 1);
	return initialY;
}

void AEaterController::eaterSpawnerFunction(int arrayLocationX, int arrayLocationY)
{
	//begins by getting GameInstance so that the location can be added
  FieldData &fieldData = FieldData::get();

	//adds the location of the wall to a global array found in GameInstance in the format of "[object identifier][xlocation][ylocation]". Z location is superfluous because it is constant for all actors
	//"w" identifier is for wall, "e" for eater, "n" for normal food pellet, "b" for bonus food pellet

	//FString arrayLocation = FString(TEXT("w") + FString::FromInt(xLocation) + FString::FromInt(yLocation));
	//FDGI->FieldData.Add(arrayLocation);

	UE_LOG(LogTemp, Log, TEXT("Made it to while"));
	/*while (FDGI->FieldData[arrayIndex] != "n") {

		spawnLocation.X = generateX();
		spawnLocation.Y = generateY();
		arrayLocationX = spawnLocation.X / 200 + 7;
		arrayLocationY = spawnLocation.Y / 200 + 7;
		arrayIndex = 15 * arrayLocationX + arrayLocationY;
	}*/
  //fieldData.cells[arrayLocationX][arrayLocationY].item = FieldData::Item::EMPTY;

	//creates the parameters for spawning based off of Unreal Documentation guidelines
	//FActorSpawnParameters spawnParams;
	//spawnParams.Owner = this;
	//spawnParams.Instigator = Instigator;
  //FVector spawnLocation(arrayLocationX * fieldData.render_scaling_factor, arrayLocationY * fieldData.render_scaling_factor, 0);
	//AEater* newEater = GetWorld()->SpawnPawn<AEater>(spawningObject, spawnLocation, FRotator::ZeroRotator, spawnParams);
}

// Called when the game starts or when spawned
void AEaterController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Log, TEXT("Eater working"));
	eaterSpawnerFunction(generateX(), generateY());
}

// Called every frame
void AEaterController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

