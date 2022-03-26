// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ObjectCanHide.generated.h"

class UBoxComponent;

UCLASS()
class PESCADOR_API AObjectCanHide : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AObjectCanHide();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void NotifyActorBeginOverlap(AActor* OtherActor);

//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
private:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* StaticMeshComponent = nullptr;

	UPROPERTY(VisibleAnywhere)
	UBoxComponent* BoxCollision = nullptr;

};
