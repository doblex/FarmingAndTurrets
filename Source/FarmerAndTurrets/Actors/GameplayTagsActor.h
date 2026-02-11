// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagAssetInterface.h"
#include "GameFramework/Actor.h"
#include "GameplayTagsActor.generated.h"

UCLASS()
class FARMERANDTURRETS_API AGameplayTagsActor : public AActor, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AGameplayTagsActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Gameplay Tags")
	FGameplayTag GameplayTag;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const;
};
