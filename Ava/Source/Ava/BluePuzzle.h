// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Puzzle.h"
#include "PushPullItem.h"
#include "Runtime/Engine/Classes/Engine/TriggerBox.h"
#include "BluePuzzle.generated.h"

/**
 * 
 */
//USTRUCT(BlueprintType)
//struct FPushCombo
//{
//	GENERATED_BODY()
//public:
//	UPROPERTY(BlueprintReadWrite, Category = "pushCombo")
//	APushPullItem* item;
//	UPROPERTY(BlueprintReadWrite, Category = "pushCombo")
//	UBoxComponent* boxCollider;
//};


UCLASS()
class AVA_API ABluePuzzle : public APuzzle
{
	GENERATED_BODY()
public:


	// Sets default values for this actor's properties
	ABluePuzzle();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BluePuzzleVariables, meta = (AllowPrivateAccess = "true"))
		TArray <APushPullItem*> pushPullObjects;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BluePuzzleVariables, meta = (AllowPrivateAccess = "true"))
		TArray <ATriggerBox*> pushPullObjectsTargets;
private:
		bool overlaps[4];


		bool checkOverlaps();


	
	
};
