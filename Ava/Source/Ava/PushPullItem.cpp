// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "PushPullItem.h"


// Sets default values
APushPullItem::APushPullItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	constrainX = false;
	constrainY = false;
	cappedX = false;
	cappedY = false;
	designatedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	designatedMesh->SetSimulatePhysics(false);
	designatedMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);

	RootComponent = designatedMesh;

	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	boxCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative,true);
	boxCollider->AttachToComponent(RootComponent, rules);
	boxCollider->SetCollisionResponseToAllChannels(ECR_Block);
	
}

// Called when the game starts or when spawned
void APushPullItem::BeginPlay()
{
	Super::BeginPlay();
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("X is: %f, Y is: %f, Z is: %f"), GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z));
	
}

// Called every frame
void APushPullItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	
	FVector location = GetActorLocation();
	float locationX = location.X;
	float locationY = location.Y;
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




