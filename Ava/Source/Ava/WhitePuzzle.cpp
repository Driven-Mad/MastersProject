// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "WhitePuzzle.h"

AWhitePuzzle::AWhitePuzzle()
{
	for (bool b : offeringsDone)
	{
		b = false;
	}
}
void AWhitePuzzle::BeginPlay()
{
	Super::BeginPlay();
	
}

void AWhitePuzzle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!bPuzzleComplete)
	{
		for (size_t index = 0; index < Offerings.Num(); index++)
		{
			if (Offerings[index]->bItemOffered)
			{
				offeringsDone[index] = true;
			}
		}
		if (checkOfferings())
		{
			bPuzzleComplete = true;
		}
	}
	
}


bool AWhitePuzzle::checkOfferings()
{
	for (bool b : offeringsDone)
	{
		if (!b)
		{
			return false;
		}
	}
	return true;
}

