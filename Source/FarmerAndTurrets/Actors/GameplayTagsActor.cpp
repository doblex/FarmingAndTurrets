// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayTagsActor.h"


// Sets default values
AGameplayTagsActor::AGameplayTagsActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameplayTagsActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameplayTagsActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGameplayTagsActor::GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const
{
	TagContainer.AddTag(GameplayTag);
}

