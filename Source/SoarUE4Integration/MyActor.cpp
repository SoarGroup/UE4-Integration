// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include <iostream>
#include "sml_Client.h"
#include <sstream>

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
	Kernel *k = Kernel::CreateKernelInNewThread();
	Agent *a = k->CreateAgent("soar");
	cout << a->ExecuteCommandLine("echo Hello World") << endl;

	string dummy;
	cin >> dummy;
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

