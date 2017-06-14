// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "StatueObject.h"


// Sets default values
AStatueObject::AStatueObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AStatueObject::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AStatueObject::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

