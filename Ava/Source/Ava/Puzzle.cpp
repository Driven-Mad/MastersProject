// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "Puzzle.h"


// Sets default values
APuzzle::APuzzle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	boxCollider->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = boxCollider;

	bPuzzleComplete = false;
}

// Called when the game starts or when spawned
void APuzzle::BeginPlay()
{
	Super::BeginPlay();
	playerReference = Cast<AMainCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

// Called every frame
void APuzzle::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	if (bPuzzleComplete)
	{
		DesignatedDoor->Open();
	}

}

