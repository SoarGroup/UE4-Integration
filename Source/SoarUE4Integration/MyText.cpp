// Fill out your copyright notice in the Description page of Project Settings.

#include "MyText.h"
#include "sml_Client.h"

using namespace sml;

// Sets default values
AMyText::AMyText()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	MyText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("RenderedText"));
	MyText->SetWorldSize(70.f);
	MyText->SetTextRenderColor(FColor::Blue);
	MyText->SetHorizontalAlignment(EHTA_Center);

}

// Called when the game starts or when spawned
void AMyText::BeginPlay()
{
	Kernel *k = Kernel::CreateKernelInNewThread();
	Agent *a = k->CreateAgent("soar");
	MyText->SetText(a->ExecuteCommandLine("echo Hello World"));
	
	
	Super::BeginPlay();
	
}

// Called every frame
void AMyText::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

