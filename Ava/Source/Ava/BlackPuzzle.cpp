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
	if (!bPuzzleComplete)
	{
		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Black, "Black Puzzle is going through tick function.");
		if (painting  && painting->bPaintingFilled)
		{
			//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Black, "Black Room Puzzle is complete.");
			bPuzzleComplete = true;
		}
	}
}
