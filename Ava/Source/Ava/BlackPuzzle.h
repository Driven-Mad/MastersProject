// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Puzzle.h"
#include "BlackPuzzle.generated.h"

/**
 * 
 */
UCLASS()
class AVA_API ABlackPuzzle : public APuzzle
{
	GENERATED_BODY()
	
	// Sets default values for this actor's properties
	ABlackPuzzle();
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	
	
};
