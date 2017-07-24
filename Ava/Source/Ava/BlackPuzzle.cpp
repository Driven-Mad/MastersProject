// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "BlackPuzzle.h"

ABlackPuzzle::ABlackPuzzle()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ABlackPuzzle::BeginPlay()
{
	Super::BeginPlay();
}

void ABlackPuzzle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
