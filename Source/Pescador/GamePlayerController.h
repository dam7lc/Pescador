// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GamePlayerController.generated.h"

class AGameCamera;
/**
 * 
 */
UCLASS()
class PESCADOR_API AGamePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void RegisterCamera(AGameCamera* CameraReference);
	AGameCamera* GetCameraPointer() const;
private:
	AGameCamera* CameraPointer = nullptr;

};
