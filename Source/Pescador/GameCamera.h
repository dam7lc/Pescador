// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraActor.h"
#include "GameCamera.generated.h"

class AGamePlayerController;

/**
 * 
 */
UCLASS()
class PESCADOR_API AGameCamera : public ACameraActor
{
	GENERATED_BODY()
	
protected:
	virtual void BeginPlay() override;

public:
	AGameCamera();
	void TryGetPlayer();
	FRotator GetCamDiff() const;

private: 
	AGamePlayerController* PlayerPointer = nullptr;
	FRotator CamDiff;
};
