// Fill out your copyright notice in the Description page of Project Settings.


#include "GamePlayerController.h"
#include "GameCamera.h"

void AGamePlayerController::RegisterCamera(AGameCamera* CameraReference) {

	UE_LOG(LogTemp, Warning, TEXT("RegisterCamera Ejecutado en tiempo: %f"), GetWorld()->TimeSeconds);
	CameraPointer = CameraReference;
	//Panopticon initial camera position
	CameraPointer->SetActorLocation(FVector(-8134.550781f, 3567.854736f, 1576.946533f));
	CameraPointer->SetActorRotation(FRotator(-27.401224f, 16.621208f, 0.0f));
}

AGameCamera* AGamePlayerController::GetCameraPointer() const {
	return CameraPointer;
}