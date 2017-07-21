// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Eater1.generated.h"

UCLASS()
class BASICEATERS_API AEater1 : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEater1();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//UPROPERTY(EditAnywhere)
	//USpringArmComponent* OurCameraSpringArm;
	//UCameraComponent* OurCamera;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

protected:
	UPROPERTY(EditAnywhere)
	USpringArmComponent* OurCameraSpringArm;
	UCameraComponent* OurCamera;

	FVector2D CameraInput;
	float ZoomFactor;
	bool bZoomingIn;

	USceneComponent* OurVisibleComponent;
	
	

	void PitchCamera(float AxisValue);
	void YawCamera(float AxisValue);
	void ZoomIn();
	void ZoomOut();

	void Front();
	void Back();
	void Right();
	void Left();

	bool Front;
	bool Back;
	bool Right;
	bool Left;
	
};