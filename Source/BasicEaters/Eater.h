// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Eater.generated.h"

UCLASS()
class BASICEATERS_API AEater : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AEater();

	int generateX();

	int generateY();

	void eaterSpawnerFunction(int xLocation, int yLocation);

	UFUNCTION()
	void MoveUp();

	UFUNCTION()
		void MoveDown();

	UFUNCTION()
		void MoveLeft();

	UFUNCTION()
		void MoveRight();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
