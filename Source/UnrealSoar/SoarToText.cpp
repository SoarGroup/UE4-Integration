// Fill out your copyright notice in the Description page of Project Settings.

#include "SoarToText.h"

#include "Soar_Agent.h"
#include "Soar_Kernel.h"

//#include "Engine/TextRenderActor.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"

// Sets default values for this component's properties
USoarToText::USoarToText()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USoarToText::BeginPlay()
{
	Super::BeginPlay();

	// ...

  Soar_Kernel::Pointer kernel = Soar_Kernel::Create();
  Soar_Agent::Pointer agent = Soar_Agent::Create(kernel, "soar");
  FText helloWorld = FText::FromString((*agent)->ExecuteCommandLine("echo Hello World"));

  auto textRender = this->GetOwner()->FindComponentByClass<UTextRenderComponent>();
  if(textRender)
    textRender->SetText(helloWorld);
}


// Called every frame
void USoarToText::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}
