// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Puzzle.h"
#include "GreenPuzzle.generated.h"

/**
 * 
 */
UCLASS()
class AVA_API AGreenPuzzle : public APuzzle
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AGreenPuzzle();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;
	
	
};
