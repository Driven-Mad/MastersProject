// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "Door.h"


// Sets default values
ADoor::ADoor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	boxCollider->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	boxCollider->SetCollisionResponseToAllChannels(ECR_Block);
	RootComponent = boxCollider;

	designatedMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorMesh"));
	designatedMesh->SetSimulatePhysics(false);
	designatedMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	FAttachmentTransformRules rules = FAttachmentTransformRules(EAttachmentRule::KeepRelative, true);
	designatedMesh->AttachToComponent(RootComponent, rules);

	static ConstructorHelpers::FObjectFinder<UCurveFloat> Curvy(TEXT("/Game/TemporaryContent/DoorSwing.DoorSwing"));
	if (Curvy.Object) {
		fCurve = Curvy.Object;
	}

	ScoreTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineScore"));

	//Bind the Callbackfuntion for the float return value
	InterpFunction.BindUFunction(this, FName{ TEXT("TimelineFloatReturn") });
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();
	//Add the float curve to the timeline and connect it to your timelines's interpolation function
	ScoreTimeline->AddInterpFloat(fCurve, InterpFunction, FName{ TEXT("Floaty") });	
}

// Called every frame
void ADoor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ADoor::TimelineFloatReturn(float val)
{
	designatedMesh->SetRelativeRotation(FRotator(0 , val, 0));
}

void ADoor::Open()
{
	// Start your Timeline or PlayFromStart() etc, can be called anywhere in this class
	ScoreTimeline->Play();
}

