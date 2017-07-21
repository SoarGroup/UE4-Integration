// Fill out your copyright notice in the Description page of Project Settings.

#include "Eater1.h"
#include "Field.h"



// Sets default values
AEater1::AEater1()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	OurCameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	OurCameraSpringArm->SetupAttachment(RootComponent);
	OurCameraSpringArm->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, 50.0f), FRotator(-60.0f, 0.0f, 0.0f));
	OurCameraSpringArm->TargetArmLength = 400.f;
	OurCameraSpringArm->bEnableCameraLag = true;
	OurCameraSpringArm->CameraLagSpeed = 3.0f;

	OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("GameCamera"));
	OurCamera->SetupAttachment(OurCameraSpringArm, USpringArmComponent::SocketName);

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void AEater1::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEater1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	{
		if (bZoomingIn)
		{
			ZoomFactor += DeltaTime / 0.5f;
		}
		else
		{
			ZoomFactor -= DeltaTime / 0.25f;
		}
		ZoomFactor = FMath::Clamp<float>(ZoomFactor, 0.0f, 1.0f);

		OurCamera->FieldOfView = FMath::Lerp<float>(90.0f, 60.0f, ZoomFactor);
		OurCameraSpringArm->TargetArmLength = FMath::Lerp<float>(400.0f, 300.0f, ZoomFactor);
	}

	{
		FRotator NewRotation = GetActorRotation();
		NewRotation.Yaw += CameraInput.X;
		SetActorRotation(NewRotation);
	}

	{
		FRotator NewRotation = OurCameraSpringArm->GetComponentRotation();
		NewRotation.Pitch = FMath::Clamp(NewRotation.Pitch + CameraInput.Y, -80.0f, -15.0f);
		OurCameraSpringArm->SetWorldRotation(NewRotation);
	}

	{
		if (!MovementInput.IsZero())
		{
			MovementInput = MovementInput.SafeNormal() * 100.0f;
			FVector NewLocation = GetActorLocation();
			NewLocation += GetActorForwardVector() * MovementInput.X * DeltaTime;
			NewLocation += GetActorRightVector() * MovementInput.Y * DeltaTime;
			SetActorLocation(NewLocation);
		}
	}
}

void AEater1::PitchCamera(float AxisValue)
{
	CameraInput.Y = AxisValue;
}

void AEater1::YawCamera(float AxisValue)
{
	CameraInput.X = AxisValue;
}

void AEater1::SetupPlayerInputComponent(class UInputComponent* InputComponent)
(
	Super::SetupPlayerInputComponent(InputComponent);

	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &AEater1::ZoomIn);
	InputComponent->BindAction("ZoomOut", IE_Released, this, &AEater1::ZoomOut);

	InputComponent->BindAxis("CameraPitch", this, &AEater1::PitchCamera);
	InputComponent->BindAxis("CameraYaw", this, &AEater1::YawCamera);
)

void AEater1::PitchCamera(float AxisValue)
{
	CameraInput.Y = AxisValue;
}

void AEater1::YawCamera(float AxisValue)
{
	CameraInput.X = AxisValue;
}

void AEater1::ZoomIn()
{
	bZoomingIn = true;
}

void AEater1::ZoomOut()
{
	bZoomingIn = false;
}
