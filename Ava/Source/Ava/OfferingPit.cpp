#include "Ava.h"
#include "PickUpItem.h"
#include "OfferingPit.h"


// Sets default values
AOfferingPit::AOfferingPit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	overlappingSphere = CreateDefaultSubobject<USphereComponent>(TEXT("overlappingSphere"));
	RootComponent = overlappingSphere;

	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, true);


	offeringPitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StatueMesh"));
	offeringPitMesh->SetSimulatePhysics(false);
	offeringPitMesh->AttachToComponent(RootComponent, rules);
}

// Called when the game starts or when spawned
void AOfferingPit::BeginPlay()
{
	Super::BeginPlay();
	bItemOffered = false;
	requiredItem = Item::Bracelet;
}

// Called every frame
void AOfferingPit::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (!bItemOffered)
	{
		TArray <AActor*> overlappingActors;
		overlappingSphere->GetOverlappingActors(overlappingActors);
		for (size_t overlappingActorIndex = 0; overlappingActorIndex < overlappingActors.Num(); overlappingActorIndex++)
		{
			APickUpItem* const overlappingTest = Cast<APickUpItem>(overlappingActors[overlappingActorIndex]);
			if (overlappingTest && overlappingTest->itemType == requiredItem)
			{
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, "Item has been offered");
				bItemOffered = true;
				overlappingTest->Destroy();
			}
		}
	}
}

