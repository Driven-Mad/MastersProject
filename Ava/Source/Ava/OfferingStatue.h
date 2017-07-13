// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DataFactory.h"
#include "OfferingStatue.generated.h"

UCLASS()
class AVA_API AOfferingStatue : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOfferingStatue();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *Alter;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *BuddaStatue;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		USphereComponent* overlappingSphere;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		Item requiredItem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		bool bItemOffered;
	
};
