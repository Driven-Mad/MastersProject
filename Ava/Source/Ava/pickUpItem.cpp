#include "Ava.h"
#include "PickUpItem.h"


// Sets default values
APickUpItem::APickUpItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	boxCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	boxCollider->SetEnableGravity(true);
	boxCollider->SetCollisionResponseToAllChannels(ECR_Block);
	boxCollider->SetSimulatePhysics(true);
	RootComponent = boxCollider;

	designatedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	designatedMesh->SetSimulatePhysics(false);
	designatedMesh->SetEnableGravity(false);
	designatedMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, true);
	designatedMesh->AttachToComponent(RootComponent, rules);

}

// Called when the game starts or when spawned
void APickUpItem::BeginPlay()
{
	Super::BeginPlay();
	startingX = GetActorLocation().X;
	startingY = GetActorLocation().Y;
	startingZ = GetActorLocation().Z;
}

// Called every frame
void APickUpItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector Location = GetActorLocation();
	float locationX = Location.X;
	float locationY = Location.Y;
	float locationZ = Location.Z;
	if (LockX)
	{
		SetActorLocation(FVector(startingX, locationY, locationZ));

	};
	if (LockY)
	{
		SetActorLocation(FVector(locationX, startingY, locationZ));

	};
	if (LockZ)
	{
		SetActorLocation(FVector(locationX, locationY, startingZ));
	};

}



#if WITH_EDITOR
void APickUpItem::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	//Create a farm based on size - Checks if the farm size is changed if so creates  farm. 
	if (PropertyName == GET_MEMBER_NAME_CHECKED(APickUpItem,itemType))
	{
		UStaticMesh * mesh = myData->Get3DRepresentationForItem(itemType);
		if (mesh != nullptr)
		{
			designatedMesh->SetVisibility(true);
			designatedMesh->SetStaticMesh(mesh);
		}
		else
		{
			designatedMesh->SetVisibility(false);
		}
		//RootComponent = designatedMesh;
	}

}
#endif