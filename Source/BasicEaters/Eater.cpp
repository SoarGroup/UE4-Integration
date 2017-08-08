// Fill out your copyright notice in the Description page of Project Settings.

#include "Eater.h"


// Sets default values
AEater::AEater()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

int AEater::generateX()
{
	int initialX = 0.f;
	initialX = FMath::RandRange(-7, 7);
	// we have a 3000px x 3000px playing field. since we want it to be 15x15, we must divide the field into 255 200px x 200px squares. -7 to 7 allows 15 squares (including 0). this function generates the x coordinate
	initialX = 200 * initialX;
	return initialX;
}

int AEater::generateY()
{
	int initialY = 0.f;
	initialY = FMath::RandRange(-7, 7);
	initialY = 200 * initialY;
	return initialY;
}

void AEater::eaterSpawnerFunction(int xLocation, int yLocation)
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
	UE_LOG(LogTemp, Log, TEXT("Made it to while"));
	/*while (FDGI->FieldData[arrayIndex] != "n") {

	spawnLocation.X = generateX();
	spawnLocation.Y = generateY();
	arrayLocationX = spawnLocation.X / 200 + 7;
	arrayLocationY = spawnLocation.Y / 200 + 7;
	arrayIndex = 15 * arrayLocationX + arrayLocationY;
	}*/
	FString arrayObject = FString(TEXT("e"));
	FDGI->FieldData[arrayIndex] = arrayObject;

	SetActorLocation(spawnLocation, false);
}

void AEater::MoveUp(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		UE_LOG(LogTemp, Log, TEXT("Up!"));

		FVector actorLocation = GetActorLocation();
		actorLocation.X += 200;
		if (actorLocation.X != 1600)
		{
			UE_LOG(LogTemp, Log, TEXT("Still Moving UP!!"));
			SetActorLocation(actorLocation, false);
		}
	}

}

void AEater::MoveDown(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		UE_LOG(LogTemp, Log, TEXT("Down!"));

		FVector actorLocation = GetActorLocation();
		actorLocation.X -= 200;
		if (actorLocation.X != -1600)
		{
			UE_LOG(LogTemp, Log, TEXT("Still Moving UP!!"));
			SetActorLocation(actorLocation, false);
		}
	}
}

void AEater::MoveLeft(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		UE_LOG(LogTemp, Log, TEXT("Left!"));

		FVector actorLocation = GetActorLocation();
		actorLocation.Y -= 200;
		if (actorLocation.Y != -1600)
		{
			
			SetActorLocation(actorLocation, false);
		}
	}
}

void AEater::MoveRight(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		UE_LOG(LogTemp, Log, TEXT("Right!");

		FVector actorLocation = GetActorLocation();
		actorLocation.Y += 200;
		if (actorLocation.Y != 1600)
		{
			UE_LOG(LogTemp, Log, TEXT("Still Moving UP!!"));
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
	PlayerInputComponent->BindAxis("MoveUp", this, &AEater::MoveUp);
	PlayerInputComponent->BindAxis("MoveDown", this, &AEater::MoveDown);
	PlayerInputComponent->BindAxis("MoveLeft", this, &AEater::MoveLeft);
	PlayerInputComponent->BindAxis("MoveRight", this, &AEater::MoveRight);

}

