//--------------------------------------------------------------------------------------------------------------------------
/// @file Door.h
/// @brief This is our door class which is apart of every puzzle to go into each room.
/// @author Lloyd Phillips
/// @version 1.0
/// @date 30/06/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class AVA_API ADoor : public AActor
{
	GENERATED_BODY()
	
public:	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for door class, Sets default values for this doors properties
	//----------------------------------------------------------------------------------------------------------------------
	ADoor();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called when the game starts or when spawned for our door.
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called every frame to update the door.
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick(float DeltaSeconds) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief DoorVariables - Will allow us to play our timeline via a curve.
	/// @param ScoreTimeline - pointer to a timeline component. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY()
		UTimelineComponent* ScoreTimeline;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief DoorVariables -  for the artist to draw to be used with timeline of door opening. 
	/// @param fCurve - curve designated by artist. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY()
		UCurveFloat* fCurve;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief - Function that binds our function to the timeline. 
	//----------------------------------------------------------------------------------------------------------------------
	FOnTimelineFloat InterpFunction{};
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief - Function to read in the value from the timeline and where to place the door. 
	/// @param - Val = Float at current time in timeline. 
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION()
		void TimelineFloatReturn(float val);

	//----------------------------------------------------------------------------------------------------------------------
	/// @brief - Function that opens to door using timeline above. 
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION()
		void Open();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief DoorVariables - The visual representation of this actor in 3D form. 
	/// @param designatedMesh - Static mesh component 3D mesh. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DoorVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *designatedMesh;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief DoorVariables - box collider which wil act as our root component for the door. 
	/// @param boxCollider - this is box component which will be our root. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = DoorVariables, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* boxCollider;
};
