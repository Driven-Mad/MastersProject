#include "Ava.h"
#include "GreenPuzzle.h"

AGreenPuzzle::AGreenPuzzle()
{

}
void AGreenPuzzle::BeginPlay()
{
	Super::BeginPlay();
}

void AGreenPuzzle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (!DesignatedStatue->bCanPlayerPray)
	{
		bPuzzleComplete = true;
	}
}
