// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "pickUpItem.h"


// Sets default values
ApickUpItem::ApickUpItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ApickUpItem::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ApickUpItem::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

