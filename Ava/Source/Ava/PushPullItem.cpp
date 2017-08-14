#include "Ava.h"
#include "PushPullItem.h"


// Sets default values
APushPullItem::APushPullItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	designatedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	designatedMesh->SetSimulatePhysics(false);
	designatedMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	RootComponent = designatedMesh;

	sphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("SphereCollision"));
	sphereCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative,true);
	sphereCollider->AttachToComponent(RootComponent, rules);
	sphereCollider->SetCollisionResponseToAllChannels(ECR_Block);
	constrainX = false;
	constrainY = false;

	cappedX = false;
	cappedY = false;

	LockX = false;
	LockY = false;
	LockZ = false;
	
}

// Called when the game starts or when spawned
void APushPullItem::BeginPlay()
{
	Super::BeginPlay();

	startingX = GetActorLocation().X;
	startingY = GetActorLocation().Y;
	startingZ = GetActorLocation().Z;


}

// Called every frame
void APushPullItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//Get actor location and split for various reasons. 
	FVector location = GetActorLocation();
	float locationX = location.X;
	float locationY = location.Y;
	float locationZ = location.Z;
	//Do lock checks first. 
	if (LockX)
	{
		SetActorLocation(FVector(startingX, locationY, location.Z));
	}
	if (LockY)
	{
		SetActorLocation(FVector(location.X, startingY, location.Z));
	}
	if (LockZ)
	{
		SetActorLocation(FVector(location.X, location.Y, startingZ));
	}


	//Check if the constraints are needed by artist. 
	if ( constrainX)
	{
		if (locationX < xMin)
		{
			SetActorLocation(FVector(xMin, location.Y, location.Z));
			cappedX = true;
		}
		if (locationX > xMax)
		{
			SetActorLocation(FVector(xMax, location.Y, location.Z));
			cappedX = true;
		}
	}

	if (constrainY)
	{
		if (locationY < yMin)
		{
			SetActorLocation(FVector(location.X, yMin,  location.Z));
			cappedY = true;
		}
		if (locationY > yMax)
		{
			SetActorLocation(FVector(location.X, yMax,  location.Z));
			cappedY = true;
		}
	}
	
}




