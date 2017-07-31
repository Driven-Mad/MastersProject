//--------------------------------------------------------------------------------------------------------------------------
/// @file RedPuzzle.h
/// @brief This is our Red Puzzle Class. It inherits from its parent class APuzzle.
/// @brief used to contain all our puzzle variables in regards to this particular room. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 24/07/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Puzzle.h"
#include "OfferingPit.h"
#include "RedPuzzle.generated.h"

UCLASS()
class AVA_API ARedPuzzle : public APuzzle
{
	GENERATED_BODY()

	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for red puzzle class, Sets default values for this puzzles's properties
	//----------------------------------------------------------------------------------------------------------------------
	ARedPuzzle();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:APuzzle - Called when the game starts or when spawned for our puzzle.
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:APuzzle - Called every frame to update the puzzle.
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick(float DeltaSeconds) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief RedPuzzleVariables - The offering pit that is required for this particular puzzle as it's requirement for completion. 
	/// @param offeringPit - An offering pit actor that contains the completion methods for this puzzle. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = RedPuzzleVariables, meta = (AllowPrivateAccess = "true"))
		AOfferingPit *offeringPit;
protected:
private:
	
};
