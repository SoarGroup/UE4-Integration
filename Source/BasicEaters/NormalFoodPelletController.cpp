// Fill out your copyright notice in the Description page of Project Settings.

#include "NormalFoodPelletController.h"
#include "FieldData.h"


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
	UE_LOG(LogTemp, Log, TEXT("Normal"))
	normalFoodPelletGenerator();
	
}

void ANormalFoodPelletController::EndPlay(const EEndPlayReason::Type endPlayReasonType) {
  FieldData &fieldData = FieldData::get();
  fieldData.reset();
}



void ANormalFoodPelletController::normalFoodPelletSpawnerFunction(int arrayLocationX, int arrayLocationY)
{
	//begins by getting GameInstance so that the location can be added
  FieldData &fieldData = FieldData::get();

	FString arrayObject = FString(TEXT("n"));
	//FDGI->FieldData[arrayIndex] = arrayObject;

	//creates the parameters for spawning based off of Unreal Documentation guidelines
	FActorSpawnParameters spawnParams;
	spawnParams.Owner = this;
	spawnParams.Instigator = Instigator;
  FVector spawnLocation(arrayLocationX * fieldData.render_scaling_factor, arrayLocationY * fieldData.render_scaling_factor, 0);
	ANormalFoodPellet* newNormalFoodPellet = GetWorld()->SpawnActor<ANormalFoodPellet>(spawningObject, spawnLocation, FRotator::ZeroRotator, spawnParams);

  fieldData.cells[arrayLocationX][arrayLocationY].set_object(newNormalFoodPellet);
}

void ANormalFoodPelletController::normalFoodPelletGenerator()
{
  FieldData &fieldData = FieldData::get();

  for (int i = 0; i != FieldData::grid_size; ++i) {
    for (int j = 0; j != FieldData::grid_size; ++j) {
      if(fieldData.cells[i][j].item == FieldData::Item::PELLET)
     		normalFoodPelletSpawnerFunction(i, j);
    }
  }
	
}

// Called every frame
void ANormalFoodPelletController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

