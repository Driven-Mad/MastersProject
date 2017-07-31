#include "Ava.h"
#include "PaintingObject.h"


// Sets default values
APaintingObject::APaintingObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	boxCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	boxCollider->SetCollisionResponseToAllChannels(ECR_Block);
	boxCollider->SetSimulatePhysics(false);
	RootComponent = boxCollider;

	designatedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PaintingMesh"));
	designatedMesh->SetSimulatePhysics(false);
	designatedMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, true);
	designatedMesh->AttachToComponent(RootComponent, rules);

	//Add all the required items. 
	RequiredItems.Add(Item::Scroll01);
	RequiredItems.Add(Item::Scroll02);
	RequiredItems.Add(Item::Scroll03);
	RequiredItems.Add(Item::Scroll04);
	RequiredItems.Add(Item::Scroll05);
	RequiredItems.Add(Item::Scroll06);
	RequiredItems.Add(Item::Scroll07);

}

// Called when the game starts or when spawned
void APaintingObject::BeginPlay()
{
	Super::BeginPlay();
	bPaintingFilled = false;
	for (bool b : itemsOffered)
	{
		b = false;
	}
}

// Called every frame
void APaintingObject::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (!bPaintingFilled)
	{
		TArray <AActor*> overlappingActors;
		boxCollider->GetOverlappingActors(overlappingActors);
		for (size_t overlappingActorIndex = 0; overlappingActorIndex < overlappingActors.Num(); overlappingActorIndex++)
		{
			APickUpItem* const overlappingTest = Cast<APickUpItem>(overlappingActors[overlappingActorIndex]);
			for (size_t itemIndex = 0; itemIndex < RequiredItems.Num(); itemIndex++)
			{
				if (overlappingTest)
				{
					if (overlappingTest->itemType == RequiredItems[itemIndex] && !itemsOffered[itemIndex])
					{
						ScrollItems[itemIndex]->itemType = RequiredItems[itemIndex];
						UStaticMesh * mesh = ScrollItems[itemIndex]->myData->Get3DRepresentationForItem(RequiredItems[itemIndex]);
						if (mesh)
						{
							
							ScrollItems[itemIndex]->designatedMesh->SetVisibility(true);
							ScrollItems[itemIndex]->designatedMesh->SetStaticMesh(mesh);
							itemsOffered[itemIndex] = true;
							GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Black, FString::Printf(TEXT("ItemOffered: %i / %i"), itemIndex, itemsOffered[itemIndex]));
							overlappingTest->Destroy();
						}
						
					}
				}
			}
		}
	}
	if (checkItemsOffered() && !bPaintingFilled)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Blue, FString::Printf(TEXT("WE HAVE FILLED PAINTING")));
		bPaintingFilled = true;
		
	}
	
}

bool APaintingObject::checkItemsOffered()
{
	for (bool b : itemsOffered)
	{
		if (!b)
		{
			return false;
		}
	}
	return true;
}
