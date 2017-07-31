//--------------------------------------------------------------------------------------------------------------------------
/// @file PushPullItem.h
/// @brief This is our Push and Pull Item Class. It inherits from its parent class AActor.
/// @brief Used to allow the player to push and pull certain items and used in the blue and black room puzzles. 
/// @author Lloyd Phillips
/// @version 2.0
/// @date 15/06/17
/// Revision History:
/// 2nd version before any user testing or bug fixes. 
/// V1: added manual box collision, as when attaching this item to a player the collisions aren't 
/// inherited from child to parent. And actually go from parent to child and so it causes 
/// clipping which causes huge issues within the game.
//--------------------------------------------------------------------------------------------------------------------------
#pragma once

#include "GameFramework/Actor.h"
#include "PushPullItem.generated.h"

UCLASS()
class AVA_API APushPullItem : public AActor
{
	GENERATED_BODY()
	
public:	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for push and pull item class, Sets default values for this push and pull item properties
	//----------------------------------------------------------------------------------------------------------------------
	APushPullItem();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called when the game starts or when spawned for our push and pull item.
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called every frame to update the push and pull item.
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick(float DeltaSeconds) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - The visual representation of this actor in 3D form. 
	/// @param designatedMesh - Static mesh component 3D mesh. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *designatedMesh;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - Check if the player is currently overlapping the push and pull item. 
	/// @param sphereCollider - USphere Component for collision. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		USphereComponent* sphereCollider;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - check if artist wants to constrain the X position. 
	/// @param constrainX - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		bool constrainX;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - check if artist wants to constrain the Y position. 
	/// @param constrainY - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		bool constrainY;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - the minimum X value that the artist wants to constrain the item too. 
	/// @param xMin - float value to constrain the items movement.  - Works if constrainX is selected. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		float xMin;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - the maximum X value that the artist wants to constrain the item too. 
	/// @param xMax - float value to constrain the items movement.  - Works if constrainX is selected. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		float xMax;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - the minimum Y value that the artist wants to constrain the item too. 
	/// @param yMin - float value to constrain the items movement. - Works if constrainY is selected. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		float yMin;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - the maximum Y value that the artist wants to constrain the item too. 
	/// @param yMax - float value to constrain the items movement.  - Works if constrainY is selected. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		float yMax;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - check if artist wants lock the Y position entirely.  
	/// @param LockY - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		bool LockY;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - check if artist wants lock the X position entirely.  
	/// @param LockX - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		bool LockX;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - check if artist wants lock the X position entirely.  
	/// @param LockZ - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		bool LockZ;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - informs us when the player has reached the xMin or xMax
	/// Available to be read anywhere to allow the disconnection of the push and pull from the player. 
	/// @param cappedX - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		bool cappedX;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pushableItemVariables - informs us when the player has reached the yMin or yMax
	/// Available to be read anywhere to allow the disconnection of the push and pull from the player. 
	/// @param cappedY - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		bool cappedY;
private:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief The starting x position of this actor.
	//----------------------------------------------------------------------------------------------------------------------
	float startingX;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief The starting y position of this actor.
	//----------------------------------------------------------------------------------------------------------------------
	float startingY;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief The starting z position of this actor.
	//----------------------------------------------------------------------------------------------------------------------
	float startingZ;
};
