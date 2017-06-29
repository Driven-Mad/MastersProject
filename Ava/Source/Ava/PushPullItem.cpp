// Fill out your copyright notice in the Description page of Project Settings.

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
	
}

// Called every frame
void APushPullItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

