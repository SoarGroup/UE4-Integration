// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
<<<<<<< HEAD
#include <iostream>
#include "sml_Client.h"
#include <sstream>

=======

#include "Soar_Agent.h"
#include "Soar_Kernel.h"

#include <iostream>
#include <sstream>


>>>>>>> 025c40a427a729d20c45aa3fc18b189e3d8dc982
using namespace std;
using namespace sml;


// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

//Puts output from cout to Unreal Output Log
class LStream : public std::stringbuf {
protected:
	int sync() {
		UE_LOG(LogTemp, Log, TEXT("%s"), *FString(str().c_str()));
		str("");
		return std::stringbuf::sync();
	}
};
// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	LStream Stream;
	cout.rdbuf(&Stream);
	cout << "some message" << endl;
<<<<<<< HEAD
	Kernel *k = Kernel::CreateKernelInNewThread();
	Agent *a = k->CreateAgent("soar");
	cout << a->ExecuteCommandLine("echo Hello World") << endl;
=======

  Soar_Kernel::Pointer kernel = Soar_Kernel::Create();
  Soar_Agent::Pointer agent = Soar_Agent::Create(kernel, "soar");
	//Kernel *k = Kernel::CreateKernelInNewThread();
	//Agent *a = k->CreateAgent("soar");
	cout << (*agent)->ExecuteCommandLine("echo Hello World") << endl;
>>>>>>> 025c40a427a729d20c45aa3fc18b189e3d8dc982

	string dummy;
	cin >> dummy;
	Super::BeginPlay();
<<<<<<< HEAD
	
=======
>>>>>>> 025c40a427a729d20c45aa3fc18b189e3d8dc982
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

