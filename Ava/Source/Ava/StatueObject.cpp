// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "StatueObject.h"


// Sets default values
AStatueObject::AStatueObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bCanPlayerPray = true;



	designatedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	designatedMesh->SetSimulatePhysics(false);
	RootComponent = designatedMesh;
	//DesignatedMesh->AttachTo(RootComponent);

	overlappingSphere = CreateDefaultSubobject<USphereComponent>(TEXT("overlappingSphere"));
	overlappingSphere->SetSphereRadius(100.f);
	overlappingSphere->AttachTo(RootComponent);

	


}

// Called when the game starts or when spawned
void AStatueObject::BeginPlay()
{
	Super::BeginPlay();
	playerReference = Cast<AMainCharacter>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
}

// Called every frame
void AStatueObject::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );
	//checkForPlayer();
}

void AStatueObject::checkForPlayer()
{
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//NOT USED AS CALLS TOO MANY TIMES
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//TArray <AActor*> overlappingActors;
	//overlappingSphere->GetOverlappingActors(overlappingActors);
	//for (int32 overlappingActorIndex = 0; overlappingActorIndex < overlappingActors.Num(); overlappingActorIndex++)
	//{
	//	AMainCharacter* const overlappingTest = Cast<AMainCharacter>(overlappingActors[overlappingActorIndex]);
	//	//if (overlappingTest) //This works
	//	if (overlappingTest && bCanPlayerPray && overlappingTest->bIsInteracting)
	//	{
	//		
	//
	//		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, statueName);
	//		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("YOU ARE PRAYING AT THE :")));
	//
	//		overlappingTest->bIsPraying = true;
	//		bCanPlayerPray = false;
	//
	//	}
	//	else if (overlappingTest && !bCanPlayerPray && overlappingTest->bIsInteracting)
	//	{
	//		//GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("YOU CAN'T PRAY AT ME ANYMORE")));
	//	}
	//
	//	//-------------------------------------------
	//	//!PRAYING INTERACTION
	//	//-------------------------------------------
	//}
}


