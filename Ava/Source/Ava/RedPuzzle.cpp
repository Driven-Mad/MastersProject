#include "Ava.h"
#include "RedPuzzle.h"

ARedPuzzle::ARedPuzzle()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ARedPuzzle::BeginPlay()
{
	Super::BeginPlay();
}

void ARedPuzzle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, "Red Puzzle is going through tick function.");
	if (!bPuzzleComplete)
	{
		if (offeringPit  && offeringPit->bItemOffered)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Red, "Red Room Puzzle is complete.");
			bPuzzleComplete = true;
		}
	}
}
