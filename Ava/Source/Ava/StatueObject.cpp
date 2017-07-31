#include "Ava.h"
#include "StatueObject.h"


// Sets default values
AStatueObject::AStatueObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	designatedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	designatedMesh->SetSimulatePhysics(false);
	RootComponent = designatedMesh;

	overlappingSphere = CreateDefaultSubobject<USphereComponent>(TEXT("overlappingSphere"));
	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, true);
	overlappingSphere->AttachToComponent(RootComponent, rules);
	overlappingSphere->SetSphereRadius(9.0f);
}

// Called when the game starts or when spawned
void AStatueObject::BeginPlay()
{
	Super::BeginPlay();
	bCanPlayerPray = true;
	isPlayerPraying = false;
}
