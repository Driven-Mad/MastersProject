// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Puzzle.h"
#include "OfferingPit.h"
#include "RedPuzzle.generated.h"

/**
 * 
 */
UCLASS()
class AVA_API ARedPuzzle : public APuzzle
{
	GENERATED_BODY()

	// Sets default values for this actor's properties
	ARedPuzzle();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = RedPuzzleVariables, meta = (AllowPrivateAccess = "true"))
		AOfferingPit *offeringPit;

private:
	
};
