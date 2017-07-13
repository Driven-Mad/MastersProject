// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "BluePuzzle.h"




ABluePuzzle::ABluePuzzle()
{

}
void ABluePuzzle::BeginPlay()
{
	Super::BeginPlay();
	for (bool b : overlaps)
	{
		b = false;
	}
}

void ABluePuzzle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!bPuzzleComplete)
	{
		for (size_t i = 0; i < pushPullObjects.Num(); i++)
		{
			TArray <AActor*> overlappingActors;
			pushPullObjectsTargets[i]->GetOverlappingActors(overlappingActors);
			for (size_t index = 0; index < overlappingActors.Num(); index++)
			{
				APushPullItem* const overlappingTest = Cast<APushPullItem>(overlappingActors[index]);
				if (overlappingTest && overlappingTest == pushPullObjects[i])
				{
					overlaps[i] = true;
					GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("overlapping: %i"), i));
				}
			}
		}

		if (checkOverlaps())
		{
			bPuzzleComplete = true;
		}
	}
	//if (!DesignatedStatue->bCanPlayerPray)
	//{
	//	bPuzzleComplete = true;
	//}
}

bool ABluePuzzle::checkOverlaps()
{
	for (bool b : overlaps)
	{
		if (!b)
		{
			return false;
		}
	}
	return true;
}
