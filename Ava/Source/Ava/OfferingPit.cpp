// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "PickUpItem.h"
#include "OfferingPit.h"


// Sets default values
AOfferingPit::AOfferingPit()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	overlappingSphere = CreateDefaultSubobject<USphereComponent>(TEXT("overlappingSphere"));
	overlappingSphere->AttachTo(RootComponent);
	RootComponent = overlappingSphere;

	requiredItem = Item::Bracelet;

	offeringPitMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StatueMesh"));
	offeringPitMesh->SetSimulatePhysics(false);
}

// Called when the game starts or when spawned
void AOfferingPit::BeginPlay()
{
	Super::BeginPlay();
	bItemOffered = false;
	
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
				GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Purple, "Item has been offered");
				bItemOffered = true;
				overlappingTest->Destroy();
			}
		}
	}
}

