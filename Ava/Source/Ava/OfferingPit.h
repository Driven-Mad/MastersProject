// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DataFactory.h"
#include "OfferingPit.generated.h"

UCLASS()
class AVA_API AOfferingPit : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOfferingPit();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = OfferingPitVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *offeringPitMesh;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = OfferingPitVariables, meta = (AllowPrivateAccess = "true"))
		USphereComponent* overlappingSphere;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = OfferingPitVariables, meta = (AllowPrivateAccess = "true"))
		Item requiredItem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = OfferingPitVariables, meta = (AllowPrivateAccess = "true"))
		bool bItemOffered;
};
