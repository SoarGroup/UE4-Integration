// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ConstructorHelpers.h"
#include "Components/SphereComponent.h"
#include "Wall.h"
#include "CoreUObject.h"
#include "GameFramework/Actor.h"
#include "NormalFoodPellet.generated.h"

UCLASS()
class BASICEATERS_API ANormalFoodPellet : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANormalFoodPellet(const FObjectInitializer& objectInitializer);

	USphereComponent* _collision;


	UFUNCTION()
	void OnFoodPelletOverlap(AActor* MyOverlappedActor, AActor* OtherActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Destroyed();
	
};
