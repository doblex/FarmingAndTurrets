// Fill out your copyright notice in the Description page of Project Settings.


#include "FacePlayerComponent.h"


// Sets default values for this component's properties
UFacePlayerComponent::UFacePlayerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFacePlayerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
	CameraManager = GetWorld()->GetFirstPlayerController()->PlayerCameraManager;

	for (auto Element : GetOwner()->GetComponentsByTag(USceneComponent::StaticClass(), RotationTag))
	{
		if (USceneComponent* ComponentToAdd = Cast<USceneComponent>(Element))
		{
			ComponentsToMove.Add(ComponentToAdd);
		}
	}
}


// Called every frame
void UFacePlayerComponent::TickComponent(float DeltaTime, ELevelTick TickType,
                                         FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	
	FVector CameraLocation = CameraManager->GetCameraLocation();
	
	for (auto Element : ComponentsToMove)
	{
		FVector ComponentNewRotation = CameraLocation - Element->GetComponentLocation();
		
		if (!bZRotation)
		{
			ComponentNewRotation.Z = 0.0f;
		}
		
		Element->SetRelativeRotation(ComponentNewRotation.Rotation());
	}
}

