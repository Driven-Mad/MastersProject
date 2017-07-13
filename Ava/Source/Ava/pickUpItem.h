// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DataFactory.h"
#include "PickUpItem.generated.h"

UCLASS()
class AVA_API APickUpItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickUpItem();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pickup, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *designatedMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pickup, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* boxCollider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pickup, meta = (AllowPrivateAccess = "true"))
		Item itemType;

	ADataFactory *myData;

	//Function to enable edits in the editor (to make the grid change size there and then).
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

};
