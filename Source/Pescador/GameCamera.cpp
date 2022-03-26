// Fill out your copyright notice in the Description page of Project Settings.


#include "GameCamera.h"
#include "GamePlayerController.h"

AGameCamera::AGameCamera() {
}

void AGameCamera::BeginPlay() {
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay Ejecutado en tiempo: %f"), GetWorld()->TimeSeconds);
	if (!PlayerPointer) {
		TryGetPlayer();
	}
}

void AGameCamera::TryGetPlayer() {
	PlayerPointer = Cast<AGamePlayerController>(GetWorld()->GetFirstPlayerController());

	UE_LOG(LogTemp, Warning, TEXT("TryGetPlayer Ejecutado en tiempo: %f"), GetWorld()->TimeSeconds);
	if (PlayerPointer) {
		PlayerPointer->RegisterCamera(this);
		
		//FVector CamVector = FVector(GetActorForwardVector().X, GetActorForwardVector().Y, 0.0f);
		//FVector X = (CamVector + FVector(1, 0, 0));

		//FVector NewX = X.GetSafeNormal();

		//// try to use up if possible
		//FVector const UpVector = (FMath::Abs(NewX.Z) < (1.f - KINDA_SMALL_NUMBER)) ? FVector(0, 0, 1.f) : FVector(1.f, 0, 0);

		//const FVector NewY = (UpVector ^ NewX).GetSafeNormal();
		//const FVector NewZ = NewX ^ NewY;

		//CamDiff = FMatrix(NewX, NewY, NewZ, FVector::ZeroVector).Rotator();
		CamDiff = GetActorRotation();
	}
}

FRotator AGameCamera::GetCamDiff() const{
	return CamDiff;
}