//--------------------------------------------------------------------------------------------------------------------------
/// @file BluePuzzle.h
/// @brief This is our Blue Puzzle Class. It inherits from its parent class APuzzle.
/// @brief used to contain all our puzzle variables in regards to this particular room. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 13/07/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Puzzle.h"
#include "PushPullItem.h"
#include "Runtime/Engine/Classes/Engine/TriggerBox.h"
#include "BluePuzzle.generated.h"

UCLASS()
class AVA_API ABluePuzzle : public APuzzle
{
	GENERATED_BODY()
public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for Blue puzzle class, Sets default values for this puzzles's properties
	//----------------------------------------------------------------------------------------------------------------------
	ABluePuzzle();
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
	/// @brief BluePuzzleVariables - the push and pull objects that can be found in the blue room, pointers to actors within the scene.  
	/// @param pushPullObjects - An array of PushPullItem Actors. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BluePuzzleVariables, meta = (AllowPrivateAccess = "true"))
		TArray <APushPullItem*> pushPullObjects;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief BluePuzzleVariables - the triggers that will show an event when overlapped with the item. 
	/// @param pushPullObjectsTargets - An array of TriggerBox's. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = BluePuzzleVariables, meta = (AllowPrivateAccess = "true"))
		TArray <ATriggerBox*> pushPullObjectsTargets;
private:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Array of four booleans to check if the overlaps of push and pull objects are done. 
	/// hardcoded array size as there's only 4 push and pull items in this puzzle.  
	//----------------------------------------------------------------------------------------------------------------------
	bool overlaps[4];
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Small function to check if all the overlaps are done. 
	//----------------------------------------------------------------------------------------------------------------------
	bool checkOverlaps();


	
	
};
