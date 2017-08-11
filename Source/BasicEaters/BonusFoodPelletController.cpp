// Fill out your copyright notice in the Description page of Project Settings.

#include "BonusFoodPelletController.h"
#include "FieldData.h"


// Sets default values
ABonusFoodPelletController::ABonusFoodPelletController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int ABonusFoodPelletController::generateX()
{
	int initialX = 0.f;
	initialX = FMath::RandRange(0, FieldData::get().grid_size - 1);
	return initialX;
}

int ABonusFoodPelletController::generateY()
{
	//same as generateX(), but for the y coordinate
	int initialY = 0.f;
	initialY = FMath::RandRange(0, FieldData::get().grid_size - 1);
	return initialY;
}

void ABonusFoodPelletController::bonusFoodPelletSpawnerFunction()
{
	//begins by getting GameInstance so that the location can be added
  FieldData &fieldData = FieldData::get();

	int arrayLocationX = generateX();
	int arrayLocationY = generateY();
	int arrayIndex = 15 * arrayLocationX + arrayLocationY;
	
  fieldData.cells[arrayLocationX][arrayLocationY].item = FieldData::Item::BONUS_PELLET;

	//creates the parameters for spawning based off of Unreal Documentation guidelines
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = Instigator;
  FVector spawnLocation(arrayLocationX * fieldData.render_scaling_factor, arrayLocationY * fieldData.render_scaling_factor, 0);
	ABonusFoodPellet* newBonusFoodPellet = GetWorld()->SpawnActor<ABonusFoodPellet>(spawningObject, spawnLocation, FRotator::ZeroRotator, spawnParams);

  fieldData.cells[arrayLocationX][arrayLocationY].set_object(newBonusFoodPellet);
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
	UE_LOG(LogTemp, Log, TEXT("BONUS FOOD PELLET"));
}


// Called every frame
void ABonusFoodPelletController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

