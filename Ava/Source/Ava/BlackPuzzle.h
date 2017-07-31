//--------------------------------------------------------------------------------------------------------------------------
/// @file BlackPuzzle.h
/// @brief This is our Black Puzzle Class. It inherits from its parent class APuzzle.
/// @brief used to contain all our puzzle variables in regards to this particular room. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 27/07/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Puzzle.h"
#include "PaintingObject.h"
#include "BlackPuzzle.generated.h"

UCLASS()
class AVA_API ABlackPuzzle : public APuzzle
{
	GENERATED_BODY()
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for black puzzle class, Sets default values for this puzzles's properties
	//----------------------------------------------------------------------------------------------------------------------
	ABlackPuzzle();
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
	/// @brief BlackPuzzleVariables - The intended item to be filled in by the player by offering iutems found in the black room. 
	/// @param painting - APaintingObject item that the player fills by dropping items.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BlackPuzzleVariables, meta = (AllowPrivateAccess = "true"))
		APaintingObject *painting;
	
	
};
