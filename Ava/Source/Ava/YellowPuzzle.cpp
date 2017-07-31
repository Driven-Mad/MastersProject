#include "Ava.h"
#include "YellowPuzzle.h"

AYellowPuzzle::AYellowPuzzle()
{
	PrimaryActorTick.bCanEverTick = true;

	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, true);

	overlappingSphere = CreateDefaultSubobject<USphereComponent>(TEXT("overlappingSphere"));
	overlappingSphere->AttachToComponent(RootComponent, rules);

	waitingPlatform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StatueMesh"));
	waitingPlatform->SetSimulatePhysics(false);
	waitingPlatform->AttachToComponent(RootComponent, rules);
}

void AYellowPuzzle::BeginPlay()
{
	Super::BeginPlay();
	currentRemaingTime = 10.f;
	requiredWaitingTime = 10.f;
	//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Yellow, "Yellow Puzzle Begin Play has started.");
}

void AYellowPuzzle::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Yellow, "Yellow Puzzle is going through tick function.");
	if (!bPuzzleComplete)
	{
		TArray <AActor*> overlappingActors;
		overlappingSphere->GetOverlappingActors(overlappingActors);
		for (size_t overlappingActorIndex = 0; overlappingActorIndex < overlappingActors.Num(); overlappingActorIndex++)
		{
			AMainCharacter* const overlappingTest = Cast<AMainCharacter>(overlappingActors[overlappingActorIndex]);
			if (overlappingTest)
			{
				//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Going through the yellow room timer.");
				currentRemaingTime -= (1.f * DeltaSeconds);
				if (currentRemaingTime <= 0.f)
				{
					overlappingTest->Inventory.Add(ThroneItem->itemType);
					ThroneItem->Destroy();
					bPuzzleComplete = true;
					//GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Yellow, "Yellow Room Puzzle is complete.");
				}
			}
			else
			{
				currentRemaingTime = requiredWaitingTime;
			}
		}
	}
}
