//--------------------------------------------------------------------------------------------------------------------------
/// @file Puzzle.h
/// @brief This is our Puzzle Class. It inherits from its parent class AActor.
/// @brief This is an abstract class only. Not meant to be instantiated. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 04/07/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once

#include "GameFramework/Actor.h"
#include "StatueObject.h"
#include "MainCharacter.h"
#include "Door.h"
#include "Puzzle.generated.h"

UCLASS(abstract)
class AVA_API APuzzle : public AActor
{
	GENERATED_BODY()
	
public:	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for yellow puzzle class, Sets default values for this puzzles's properties
	//----------------------------------------------------------------------------------------------------------------------
	APuzzle();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called when the game starts or when spawned for our puzzle.
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called every frame to update the puzzle.
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick(float DeltaSeconds) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PuzzleVariables - box collider which wil act as our root component for the puzzles. 
	/// @param boxCollider - this is box component which will be our root. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PuzzleVariables, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* boxComponent;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PuzzleVariables - Each puzzle will require a statue to pray at, this is a pointer to an actor within the game. 
	/// @param DesignatedStatue - an Instance of AStatueObject that is within the scene related to this puzzle.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PuzzleVariables, meta = (AllowPrivateAccess = "true"))
		AStatueObject* DesignatedStatue;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PuzzleVariables - Each puzzle will require a door that is required to be opened
	/// this is a pointer to an actor within the game. 
	/// @param DesignatedDoor - an Instance of ADoor that is within the scene related to this puzzle.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PuzzleVariables, meta = (AllowPrivateAccess = "true"))
		ADoor* DesignatedDoor;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PuzzleVariables - check if the puzzle has been completed. 
	/// @param bPuzzleComplete - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PuzzleVariables, meta = (AllowPrivateAccess = "true"))
		bool bPuzzleComplete;
protected:
private:

	
};
