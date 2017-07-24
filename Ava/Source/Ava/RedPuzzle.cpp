// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "RedPuzzle.h"

ARedPuzzle::ARedPuzzle()
{
	//PrimaryActorTick.bCanEverTick = true;
}

void ARedPuzzle::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Purple, "STARTED WHORE");
}

void ARedPuzzle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Purple, "inLoop");
	if (!bPuzzleComplete)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Purple, "inLoop2");
		if (offeringPit  && offeringPit->bItemOffered)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Purple, "Done");
			bPuzzleComplete = true;
		}
	}
}
