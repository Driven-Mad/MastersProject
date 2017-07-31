//--------------------------------------------------------------------------------------------------------------------------
/// @file YellowPuzzle.h
/// @brief This is our Yellow Puzzle Class. It inherits from its parent class APuzzle.
/// @brief used to contain all our puzzle variables in regards to this particular room. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 27/07/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Puzzle.h"
#include "PickUpItem.h"
#include "YellowPuzzle.generated.h"

UCLASS()
class AVA_API AYellowPuzzle : public APuzzle
{
	GENERATED_BODY()
public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for yellow puzzle class, Sets default values for this puzzles's properties
	//----------------------------------------------------------------------------------------------------------------------
	AYellowPuzzle();
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
	/// @brief YellowPuzzleVariables - this is the static mesh component which the
	/// player needs to stand on, the overlappingsphere to match the size of this.
	/// Mesh inteded to be a circle mat.
	/// @param waitingPlatform - mesh for platform 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = YellowPuzzleVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *waitingPlatform;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief YellowPuzzleVariables - Colliding sphere to indicate to us when the player will hit the mat
	/// Align with the waiting platform static mesh that the artists decide.
	/// @param overlappingSphere - this is the overlapping sphere.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = YellowPuzzleVariables, meta = (AllowPrivateAccess = "true"))
		USphereComponent *overlappingSphere;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief YellowPuzzleVariables - The intended item to be picked up by the user.
	/// artists to choose where to place.
	/// @param ThroneItem - APickUpItem item that the play picks up by waiting.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = YellowPuzzleVariables, meta = (AllowPrivateAccess = "true"))
		APickUpItem* ThroneItem;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief YellowPuzzleVariables - The intended wait time for the user
	/// @param requiredWaitingTime - Time required for the player to wait to complete the game. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = YellowPuzzleVariables, meta = (AllowPrivateAccess = "true"))
		float requiredWaitingTime;

protected:
private:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief The current remaining time for the required waiting times. 
	//----------------------------------------------------------------------------------------------------------------------
	float currentRemaingTime;
	
	
};
