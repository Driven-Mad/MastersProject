#include "Ava.h"
#include "WhitePuzzle.h"

AWhitePuzzle::AWhitePuzzle()
{
	PrimaryActorTick.bCanEverTick = true;

}
void AWhitePuzzle::BeginPlay()
{
	Super::BeginPlay();
	//Make sure always set too true. 
	for (bool b : offeringsDone)
	{
		b = false;
	}
}

void AWhitePuzzle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::White, "White Puzzle is going through tick function");
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
			secondDoorToOpen->Open();
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

