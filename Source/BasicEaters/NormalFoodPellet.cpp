// Fill out your copyright notice in the Description page of Project Settings.

#include "NormalFoodPellet.h"
#include "Eater.h"

// Sets default values
ANormalFoodPellet::ANormalFoodPellet(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	_collision = CreateDefaultSubobject<USphereComponent>(TEXT("RootComponent"));

	_collision->SetSphereRadius(50.f);
	
	OnActorBeginOverlap.AddDynamic(this, &ANormalFoodPellet::OnFoodPelletOverlap);

	RootComponent = _collision;

	
}



void ANormalFoodPellet::OnFoodPelletOverlap(AActor* MyOverlappedActor, AActor* OtherActor) {
  // TODO: Fix this
	//if (!OtherActor->IsA(ANormalFoodPellet::StaticClass())) {
	//	Destroy();
	//}
}



// Called when the game starts or when spawned
void ANormalFoodPellet::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANormalFoodPellet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

