// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DataFactory.h"
#include "StatueObject.generated.h"

UCLASS()
class AVA_API AStatueObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AStatueObject();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	ADataFactory* Data;
	Statue enumStatueChoice;
private:


	
	
};
