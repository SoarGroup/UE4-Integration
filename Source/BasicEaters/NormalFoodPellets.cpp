// Fill out your copyright notice in the Description page of Project Settings.

#include "NormalFoodPellets.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"

// Sets default values
ANormalFoodPellets::ANormalFoodPellets()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"));
	RootComponent = PickupRoot;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FoodPellet")); 
	PickupMesh->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	PickupBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupBox"));
	PickupBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
	PickupBox->bGenerateOverlapEvents = true;
	PickupBox->OnComponentBeginOverlap.AddDynamic(this, &ANormalFoodPellets::OnPlayerEnterPickupBox);
	PickupBox->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void ANormalFoodPellets::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANormalFoodPellets::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ANormalFoodPellets::OnPlayerEnterPickupBox(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Destroy();
}

