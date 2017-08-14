// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NormalFoodPellet.h"
#include "NormalFoodPelletController.generated.h"

UCLASS()
class BASICEATERS_API ANormalFoodPelletController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANormalFoodPelletController();

	void normalFoodPelletSpawnerFunction(int xLocation, int yLocation);

	void normalFoodPelletGenerator();

	UPROPERTY(EditDefaultsOnly, Category = "Spawning Object")
		TSubclassOf<ANormalFoodPellet> spawningObject;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

  virtual void EndPlay(const EEndPlayReason::Type endPlayReasonType) override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
