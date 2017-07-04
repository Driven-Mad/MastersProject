// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "StatueObject.h"
#include "MainCharacter.h"
#include "Door.h"
#include "Puzzle.generated.h"

UCLASS()
class AVA_API APuzzle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APuzzle();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PuzzleVariables, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* boxCollider;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PuzzleVariables, meta = (AllowPrivateAccess = "true"))
		AStatueObject* DesignatedStatue;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PuzzleVariables, meta = (AllowPrivateAccess = "true"))
		ADoor* DesignatedDoor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PuzzleVariables, meta = (AllowPrivateAccess = "true"))
		AMainCharacter* playerReference;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PuzzleVariables, meta = (AllowPrivateAccess = "true"))
		bool bPuzzleComplete;
	

	
};
