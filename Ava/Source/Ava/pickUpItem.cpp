// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "PickUpItem.h"


// Sets default values
APickUpItem::APickUpItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	boxCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	boxCollider->SetCollisionResponseToAllChannels(ECR_Block);
	RootComponent = boxCollider;

	designatedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	designatedMesh->SetSimulatePhysics(true);
	designatedMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, true);
	designatedMesh->AttachToComponent(RootComponent, rules);

}

// Called when the game starts or when spawned
void APickUpItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickUpItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}



#if WITH_EDITOR
void APickUpItem::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName PropertyName = (PropertyChangedEvent.Property != NULL) ? PropertyChangedEvent.Property->GetFName() : NAME_None;
	//Create a farm based on size - Checks if the farm size is changed if so creates  farm. 
	if (PropertyName == GET_MEMBER_NAME_CHECKED(APickUpItem,itemType))
	{
		designatedMesh->SetStaticMesh(myData->Get3DRepresentationForItem(itemType));
		//RootComponent = designatedMesh;
	}

}
#endif