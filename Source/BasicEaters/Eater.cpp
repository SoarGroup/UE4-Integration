// Fill out your copyright notice in the Description page of Project Settings.

#include "Eater.h"
#include "FieldData.h"

// Sets default values
AEater::AEater()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int AEater::generateX()
{
	int initialX = 0.f;
	initialX = FMath::RandRange(0, FieldData::get().grid_size - 1);
	return initialX;
}

int AEater::generateY()
{
	int initialY = 0.f;
	initialY = FMath::RandRange(0, FieldData::get().grid_size - 1);
	return initialY;
}

void AEater::eaterSpawnerFunction(int arrayLocationX, int arrayLocationY)
{
	//begins by getting GameInstance so that the location can be added
  FieldData &fieldData = FieldData::get();

	//adds the location of the wall to a global array found in GameInstance in the format of "[object identifier][xlocation][ylocation]". Z location is superfluous because it is constant for all actors
	//"w" identifier is for wall, "e" for eater, "n" for normal food pellet, "b" for bonus food pellet

	//FString arrayLocation = FString(TEXT("w") + FString::FromInt(xLocation) + FString::FromInt(yLocation));
	//FDGI->FieldData.Add(arrayLocation);

	//UE_LOG(LogTemp, Log, TEXT("Made it to while"));
	/*while (FDGI->FieldData[arrayIndex] != "n") {

	spawnLocation.X = generateX();
	spawnLocation.Y = generateY();
	arrayLocationX = spawnLocation.X / 200 + 7;
	arrayLocationY = spawnLocation.Y / 200 + 7;
	arrayIndex = 15 * arrayLocationX + arrayLocationY;
	}*/
  fieldData.cells[arrayLocationX][arrayLocationY].item = FieldData::Item::EATER;
  fieldData.cells[arrayLocationX][arrayLocationY].clear_object();
  fieldData.eater_pos = std::make_pair(arrayLocationX, arrayLocationY);

  FVector spawnLocation(arrayLocationX * fieldData.render_scaling_factor, arrayLocationY * fieldData.render_scaling_factor, 0);
	SetActorLocation(spawnLocation, false);
}

void AEater::MoveUp()
{
	if (Controller != NULL)
	{

		UE_LOG(LogTemp, Log, TEXT("Up!"));
    FieldData &fieldData = FieldData::get();
		FVector actorLocation = GetActorLocation();
		
    int arrayLocationX = fieldData.eater_pos.first + 1;
    int arrayLocationY = fieldData.eater_pos.second;
		if (arrayLocationX != fieldData.grid_size && (fieldData.cells[arrayLocationX][arrayLocationY].item != FieldData::Item::WALL))
		{
			UE_LOG(LogTemp, Log, TEXT("Still Moving UP!!"));
      fieldData.cells[arrayLocationX][arrayLocationY].take_object(fieldData.cells[fieldData.eater_pos.first][fieldData.eater_pos.second]);
      fieldData.cells[arrayLocationX][arrayLocationY].item = FieldData::Item::EATER;
      fieldData.cells[fieldData.eater_pos.first][fieldData.eater_pos.second].item = FieldData::Item::EMPTY;
      fieldData.eater_pos.first = arrayLocationX;
      fieldData.eater_pos.second = arrayLocationY;
      FVector actorLocation(arrayLocationX * fieldData.render_scaling_factor, arrayLocationY * fieldData.render_scaling_factor, 0);
			SetActorLocation(actorLocation, false);
		}
	}

}

void AEater::MoveDown()
{
	if (Controller != NULL)
	{
		UE_LOG(LogTemp, Log, TEXT("Down!"));

    FieldData &fieldData = FieldData::get();
		FVector actorLocation = GetActorLocation();

    int arrayLocationX = fieldData.eater_pos.first - 1;
    int arrayLocationY = fieldData.eater_pos.second;
    if (arrayLocationX != -1 && (fieldData.cells[arrayLocationX][arrayLocationY].item != FieldData::Item::WALL))
		{
			UE_LOG(LogTemp, Log, TEXT("Still Moving DOWN!!"));
      fieldData.cells[arrayLocationX][arrayLocationY].take_object(fieldData.cells[fieldData.eater_pos.first][fieldData.eater_pos.second]);
      fieldData.cells[arrayLocationX][arrayLocationY].item = FieldData::Item::EATER;
      fieldData.cells[fieldData.eater_pos.first][fieldData.eater_pos.second].item = FieldData::Item::EMPTY;
      fieldData.eater_pos.first = arrayLocationX;
      fieldData.eater_pos.second = arrayLocationY;
      FVector actorLocation(arrayLocationX * fieldData.render_scaling_factor, arrayLocationY * fieldData.render_scaling_factor, 0);
      SetActorLocation(actorLocation, false);
		}
	}
}

void AEater::MoveLeft()
{
	if (Controller != NULL)
	{
		UE_LOG(LogTemp, Log, TEXT("Left!"));

    FieldData &fieldData = FieldData::get();
		FVector actorLocation = GetActorLocation();

    int arrayLocationX = fieldData.eater_pos.first;
    int arrayLocationY = fieldData.eater_pos.second - 1;
    if (arrayLocationY != -1 && (fieldData.cells[arrayLocationX][arrayLocationY].item != FieldData::Item::WALL))
    {
      UE_LOG(LogTemp, Log, TEXT("Still Moving LEFT!!"));
      fieldData.cells[arrayLocationX][arrayLocationY].take_object(fieldData.cells[fieldData.eater_pos.first][fieldData.eater_pos.second]);
      fieldData.cells[arrayLocationX][arrayLocationY].item = FieldData::Item::EATER;
      fieldData.cells[fieldData.eater_pos.first][fieldData.eater_pos.second].item = FieldData::Item::EMPTY;
      fieldData.eater_pos.first = arrayLocationX;
      fieldData.eater_pos.second = arrayLocationY;
      FVector actorLocation(arrayLocationX * fieldData.render_scaling_factor, arrayLocationY * fieldData.render_scaling_factor, 0);
      SetActorLocation(actorLocation, false);
    }
	}
}

void AEater::MoveRight()
{
	if (Controller != NULL)
	{
    FieldData &fieldData = FieldData::get();
		FVector actorLocation = GetActorLocation();

    int arrayLocationX = fieldData.eater_pos.first;
    int arrayLocationY = fieldData.eater_pos.second + 1;
    if (arrayLocationY != fieldData.grid_size && (fieldData.cells[arrayLocationX][arrayLocationY].item != FieldData::Item::WALL))
    {
      UE_LOG(LogTemp, Log, TEXT("Still Moving RIGHT!!"));
      fieldData.cells[arrayLocationX][arrayLocationY].take_object(fieldData.cells[fieldData.eater_pos.first][fieldData.eater_pos.second]);
      fieldData.cells[arrayLocationX][arrayLocationY].item = FieldData::Item::EATER;
      fieldData.cells[fieldData.eater_pos.first][fieldData.eater_pos.second].item = FieldData::Item::EMPTY;
      fieldData.eater_pos.first = arrayLocationX;
      fieldData.eater_pos.second = arrayLocationY;
      FVector actorLocation(arrayLocationX * fieldData.render_scaling_factor, arrayLocationY * fieldData.render_scaling_factor, 0);
      SetActorLocation(actorLocation, false);
    }
	}
}

// Called when the game starts or when spawned
void AEater::BeginPlay()
{
	Super::BeginPlay();
	eaterSpawnerFunction(generateX(), generateY());
}

// Called every frame
void AEater::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEater::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
  PlayerInputComponent->BindAction("Front", IE_Pressed, this, &AEater::MoveUp);
  PlayerInputComponent->BindAction("Back", IE_Pressed, this, &AEater::MoveDown);
  PlayerInputComponent->BindAction("Right", IE_Pressed, this, &AEater::MoveRight);
  PlayerInputComponent->BindAction("Left", IE_Pressed, this, &AEater::MoveLeft);

}
