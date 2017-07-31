#include "Ava.h"
#include "PickUpItem.h"
#include "OfferingStatue.h"


// Sets default values
AOfferingStatue::AOfferingStatue()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	overlappingSphere = CreateDefaultSubobject<USphereComponent>(TEXT("overlappingSphere"));
	overlappingSphere->AttachTo(RootComponent);
	RootComponent = overlappingSphere;

	Alter = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("AlterMesh"));
	Alter->SetSimulatePhysics(false);
	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, true);
	Alter->AttachToComponent(RootComponent, rules);
	
	BuddaStatue = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StatueMesh"));
	BuddaStatue->SetSimulatePhysics(false);
	BuddaStatue->AttachToComponent(RootComponent, rules);

	OfferingItem = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OfferingMesh"));
	OfferingItem->SetSimulatePhysics(false);
	OfferingItem->AttachToComponent(RootComponent, rules);

}

// Called when the game starts or when spawned
void AOfferingStatue::BeginPlay()
{
	Super::BeginPlay();
	bItemOffered = false;

}

// Called every frame
void AOfferingStatue::Tick( float DeltaTime )
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
				bItemOffered = true;
				ItemData e = ADataFactory::Items[requiredItem];
				UStaticMesh* mesh = Cast <UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, e[ItemDataVariables::itemMeshFilepath].GetCharArray().GetData()));
				OfferingItem->SetStaticMesh(mesh);
				overlappingTest->Destroy();
			}
		}
	}

}

