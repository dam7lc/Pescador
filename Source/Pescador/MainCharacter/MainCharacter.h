// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class UBoxComponent;
class AGamePlayerController;
class AGameCamera;

enum CameraModes {
	FP,
	Aim
};

UCLASS()
class PESCADOR_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();
	void MoveForward(float Input);
	void MoveRight(float Input);
	void CameraX(float Input);
	void CameraY(float Input);
	void Aim(float Input);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PossessedBy(AController* NewController);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	UPROPERTY(VisibleAnywhere)
		UCameraComponent* CameraComponent = nullptr;
	UPROPERTY(VisibleAnywhere)
		USpringArmComponent* SpringArmComponent = nullptr;
	UPROPERTY(VisibleAnywhere)
		UBoxComponent* SpringArmCollision = nullptr;

	FRotator DefaultArmRotation = FRotator(0.0f, 0.0f, 0.0f);
	FRotator AimArmRotation = FRotator(-60, 0.0f, 0.0f);
	float DefaultArmLength = 800.0f;
	float AimArmLength = 2000.0f;
	CameraModes ECameraMode = CameraModes::FP;
	AGamePlayerController* ControlPointer = nullptr;
	AGameCamera* CameraPointer = nullptr;
	float TiempoLerpRotacion = 0.0f;
	float DuracionLerp = 2.0f;
	FQuat InitialRotation;
	FQuat ExpectedRotation;
	bool bLerpRotation = false;
	FVector VectorDireccion = FVector(0,0,0);
	};
