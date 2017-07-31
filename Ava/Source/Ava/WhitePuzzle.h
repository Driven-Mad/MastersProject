//--------------------------------------------------------------------------------------------------------------------------
/// @file WhitePuzzle.h
/// @brief This is our White Puzzle Class. It inherits from its parent class APuzzle.
/// @brief used to contain all our puzzle variables in regards to this particular room. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 27/07/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Puzzle.h"
#include "OfferingStatue.h"
#include "WhitePuzzle.generated.h"

UCLASS()
class AVA_API AWhitePuzzle : public APuzzle
{
	GENERATED_BODY()
	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for White puzzle class, Sets default values for this puzzles's properties
	//----------------------------------------------------------------------------------------------------------------------
	AWhitePuzzle();
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
	/// @brief The offering statues that have required items for this particular puzzle which can be found round the white room. 
	/// @param Offerings - An array of Offering Statue Actors. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = WhitePuzzleVariables, meta = (AllowPrivateAccess = "true"))
		TArray <AOfferingStatue*> Offerings;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Unlike the other rooms, the white room requires two doors, one to open to the hallway.
	/// whilst the other is to open the next room accross the hallway. 
	/// @param secondDoorToOpen -ADoor actor. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = WhitePuzzleVariables, meta = (AllowPrivateAccess = "true"))
		ADoor* secondDoorToOpen;

protected:
private: 
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Array of three booleans to check if the offering statues have had their items offered. 
	/// hardcoded array size as there's only 3 offereing statues for this puzzle. 
	//----------------------------------------------------------------------------------------------------------------------
	bool offeringsDone[3];
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Small function to check if all the offerings are done. 
	//----------------------------------------------------------------------------------------------------------------------
	bool checkOfferings();
};
