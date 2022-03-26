// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/BoxComponent.h"
#include "../GamePlayerController.h"
#include "../GameCamera.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	InitialRotation = GetMesh()->GetComponentQuat();
	if (CameraPointer) {
		FVector CamVector = FVector(CameraPointer->GetActorForwardVector().X, CameraPointer->GetActorForwardVector().Y, 0.0f);
		FVector X = VectorDireccion.RotateAngleAxis(CameraPointer->GetCamDiff().Yaw, FVector(0,0,1));
		//UE_LOG(LogTemp, Warning, TEXT("Angle: %s, CameraPointer: %f"), *CameraPointer->GetCamDiff().ToString(), CameraPointer->GetActorRotation().Yaw);
		if (!X.ToOrientationQuat().Equals(ExpectedRotation) && !VectorDireccion.Equals(FVector::ZeroVector)) { //Do everytime direction changes
			ExpectedRotation = X.ToOrientationQuat();
			TiempoLerpRotacion = 0.0f;
			bLerpRotation = true;
			UE_LOG(LogTemp, Warning, TEXT("IniciaLerp %f"), GetWorld()->TimeSeconds);
		}
	}
	if (bLerpRotation) { //Funcion lerp para rotacion del mesh en base a la direccion
		float lerpAlpha = TiempoLerpRotacion / DuracionLerp;
		GetMesh()->SetWorldRotation(FMath::Lerp(InitialRotation, ExpectedRotation, lerpAlpha));
		TiempoLerpRotacion += DeltaTime;
		if (lerpAlpha > 1.0f) {
			bLerpRotation = false;
		}
	}
	
}

void AMainCharacter::PossessedBy(AController* NewController) {
	ControlPointer = Cast<AGamePlayerController>(NewController);
	if (ControlPointer) {
		CameraPointer = ControlPointer->GetCameraPointer();
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis("CameraX", this, &AMainCharacter::CameraX);
	PlayerInputComponent->BindAxis("CameraY", this, &AMainCharacter::CameraY);
	PlayerInputComponent->BindAxis("Aim", this, &AMainCharacter::Aim);
}

void AMainCharacter::MoveForward(float Input) {
	if (CameraPointer) {
		AddMovementInput(FVector(CameraPointer->GetActorForwardVector().X, CameraPointer->GetActorForwardVector().Y, 0.0f), Input, false);
		VectorDireccion.X = Input;
	}
	else {
		CameraPointer = ControlPointer->GetCameraPointer();
	}
}

void AMainCharacter::MoveRight(float Input) {
	if (CameraPointer) {
		AddMovementInput(FVector(CameraPointer->GetActorRightVector().X, CameraPointer->GetActorRightVector().Y, 0.0f), Input, false);
		VectorDireccion.Y = Input;
	}
}

void AMainCharacter::CameraX(float Input) {
	if (ECameraMode == CameraModes::Aim) {
		//AddControllerYawInput(Input);
	}
}

void AMainCharacter::CameraY(float Input) {
	if (ECameraMode == CameraModes::FP) {
		//AddControllerPitchInput(-Input);
	}
}

void AMainCharacter::Aim(float Input) {
	/*if (FMath::IsNearlyEqual(Input, 1.0f) && ECameraMode == CameraModes::FP) {
		SpringArmComponent->TargetArmLength = AimArmLength;
		SpringArmComponent->SetRelativeRotation(AimArmRotation);
		ECameraMode = CameraModes::Aim;
	}
	else if (FMath::IsNearlyEqual(Input, 0.0f) && ECameraMode == CameraModes::Aim) {
		SpringArmComponent->TargetArmLength = DefaultArmLength;
		SpringArmComponent->SetRelativeRotation(DefaultArmRotation);
		ECameraMode = CameraModes::FP;
	}*/
}
