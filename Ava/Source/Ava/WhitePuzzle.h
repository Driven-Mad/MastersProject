// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Puzzle.h"
#include "OfferingStatue.h"
#include "WhitePuzzle.generated.h"

/**
 * 
 */
UCLASS()
class AVA_API AWhitePuzzle : public APuzzle
{
	GENERATED_BODY()
	
	// Sets default values for this actor's properties
	AWhitePuzzle();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = WhitePuzzleVariables, meta = (AllowPrivateAccess = "true"))
		TArray <AOfferingStatue*> Offerings;
	
private: 
	bool offeringsDone[3];

	bool checkOfferings();
};
