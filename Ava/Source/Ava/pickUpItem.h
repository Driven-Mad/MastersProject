//--------------------------------------------------------------------------------------------------------------------------
/// @file PickUpItem.h
/// @brief This is our pickup item class, used to work with our data factory class to create items within our game. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 15/06/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "GameFramework/Actor.h"
#include "DataFactory.h"
#include "PickUpItem.generated.h"

UCLASS()
class AVA_API APickUpItem : public AActor
{
	GENERATED_BODY()
	
public:	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for PickUp Item class, Sets default values for this puzzles's properties
	//----------------------------------------------------------------------------------------------------------------------
	APickUpItem();	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called when the game starts or when spawned for our push and pull item.
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called every frame to update the pick up item.
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick(float DeltaSeconds) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called everytime a selected variable or property of this class is changed. 
	/// @param DeltaSeconds - the event change that will trigger this. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pickup - The visual representation of this actor in 3D form. 
	/// @param designatedMesh - Static mesh component 3D mesh. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pickup, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *designatedMesh;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pickup - box collider which wil act as our root component for the items. 
	/// @param boxCollider - this is box component which will be our root. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pickup, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* boxCollider;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pickup - Used to designate certain types of paths within our game such as 3D representation etc. 
	/// @param itemType - this is box component which will be our root. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pickup, meta = (AllowPrivateAccess = "true"))
		Item itemType;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pickup - check if artist wants lock the Y position entirely.  
	/// @param LockY - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pickup, meta = (AllowPrivateAccess = "true"))
		bool LockY;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pickup - check if artist wants lock the X position entirely.  
	/// @param LockX - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pickup, meta = (AllowPrivateAccess = "true"))
		bool LockX;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief pickup - check if artist wants lock the X position entirely.  
	/// @param LockZ - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pickup, meta = (AllowPrivateAccess = "true"))
		bool LockZ;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief The data factory used to create these items. 
	//----------------------------------------------------------------------------------------------------------------------
	ADataFactory *myData;
protected:
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
