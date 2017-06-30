// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class AVA_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADoor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
		UTimelineComponent* ScoreTimeline;

	UPROPERTY()
		UCurveFloat* fCurve;

	FOnTimelineFloat InterpFunction{};

	UFUNCTION()
		void TimelineFloatReturn(float val);

	UFUNCTION()
		void Open();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DoorVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *designatedMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DoorVariables, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* boxCollider;

	
};
