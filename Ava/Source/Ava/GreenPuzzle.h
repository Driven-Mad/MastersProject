//--------------------------------------------------------------------------------------------------------------------------
/// @file GreenPuzzle.h
/// @brief This is our green Puzzle Class. It inherits from its parent class APuzzle.
/// @brief used to contain all our puzzle variables in regards to this particular room. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 04/07/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Puzzle.h"
#include "GreenPuzzle.generated.h"

UCLASS()
class AVA_API AGreenPuzzle : public APuzzle
{
	GENERATED_BODY()
	
public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for green puzzle class, Sets default values for this puzzles's properties
	//----------------------------------------------------------------------------------------------------------------------
	AGreenPuzzle();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:APuzzle - Called when the game starts or when spawned for our puzzle.
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:APuzzle - Called every frame to update the puzzle.
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick(float DeltaSeconds) override;
	
	
};
