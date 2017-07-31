#include "Ava.h"
#include "Puzzle.h"


// Sets default values
APuzzle::APuzzle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	boxComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = boxComponent;
}

// Called when the game starts or when spawned
void APuzzle::BeginPlay()
{
	Super::BeginPlay();
	bPuzzleComplete = false;
}

// Called every frame
void APuzzle::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	if (bPuzzleComplete)
	{
		//open designated door when the puzzle is complete.
		DesignatedDoor->Open();
	}
}

