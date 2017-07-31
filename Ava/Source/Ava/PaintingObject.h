//--------------------------------------------------------------------------------------------------------------------------
/// @file PaintingObject.h
/// @brief This is our Painting Object Class. It inherits from its parent class AActor.
/// @brief used within the black puzzle room, to collect 8 scroll items from around the room
/// and allocate to this painting to complete the image. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 27/07/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------

#pragma once

#include "GameFramework/Actor.h"
#include "PickUpItem.h"
#include "PaintingObject.generated.h"

UCLASS()
class AVA_API APaintingObject : public AActor
{
	GENERATED_BODY()
	
public:	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for Painting objects, Sets default values for the actor.
	//----------------------------------------------------------------------------------------------------------------------
	APaintingObject();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called when the game starts or when spawned for our object.
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called every frame to update the object.
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick(float DeltaSeconds) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PaintingObjectVariables - The visual representation of this actor in 3D form. 
	/// @param designatedMesh - Static mesh component 3D mesh. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PaintingObjectVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *designatedMesh;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PaintingObjectVariables - box collider which wil act as our root component for the object. 
	/// @param boxCollider - this is box component which will be our root. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PaintingObjectVariables, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* boxCollider;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PaintingObjectVariables - The PickUp Items that are required items for this particular 
	/// puzzle which can be found round the black room. Pointers to the already spawned items. 
	/// @param ScrollItems - An array of pick up items Actors. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PaintingObjectVariables , meta = (AllowPrivateAccess = "true"))
		TArray <APickUpItem*> ScrollItems;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PaintingObjectVariables - Check if painting has been filled. 
	/// @param bPaintingFilled - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = PaintingObjectVariables, meta = (AllowPrivateAccess = "true"))
		bool bPaintingFilled;
protected:
private:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Array of seven items that are required to complete this puzzle. 
	//----------------------------------------------------------------------------------------------------------------------
	TArray <Item> RequiredItems;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Array of seven booleans to check if the painting has had the found items offered. 
	/// hardcoded array size as there's only 7 offereings for this puzzle. 
	//----------------------------------------------------------------------------------------------------------------------
	bool itemsOffered[7];
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Small function to check if all the offerings are done. 
	//----------------------------------------------------------------------------------------------------------------------
	bool checkItemsOffered();
	
};
