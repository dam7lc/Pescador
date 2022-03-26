// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectCanHide.h"
#include "Components/BoxComponent.h"

// Sets default values
AObjectCanHide::AObjectCanHide()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("Static Mesh"));
	RootComponent = StaticMeshComponent;
	StaticMeshComponent->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Overlap);
	StaticMeshComponent->SetGenerateOverlapEvents(true);

	
}

// Called when the game starts or when spawned
void AObjectCanHide::BeginPlay()
{
	Super::BeginPlay();
	
}

void AObjectCanHide::NotifyActorBeginOverlap(AActor* OtherActor){
	UE_LOG(LogTemp, Warning, TEXT("%s"), *OtherActor->GetFName().ToString());
	TArray<UPrimitiveComponent*> OverlappingComponents;
	GetOverlappingComponents(OverlappingComponents);
	for (UPrimitiveComponent* Component : OverlappingComponents) {
		UE_LOG(LogTemp, Warning, TEXT("Component: %s"), *Component->GetFName().ToString());
	}
	
}
