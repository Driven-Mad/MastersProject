//--------------------------------------------------------------------------------------------------------------------------
/// @file OfferingStatue.h
/// @brief This is our Offering Statue class, to be used within the white room puzzle.  
/// @author Lloyd Phillips
/// @version 1.0
/// @date 25/06/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "GameFramework/Actor.h"
#include "DataFactory.h"
#include "OfferingStatue.generated.h"

UCLASS()
class AVA_API AOfferingStatue : public AActor
{
	GENERATED_BODY()
	
public:	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for an Offering Statue, Sets default values for the actor.
	//----------------------------------------------------------------------------------------------------------------------
	AOfferingStatue();	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called when the game starts or when spawned for our actor.
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called every frame to update the actor.
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick(float DeltaSeconds) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief StatueVariables - The visual representation of this actors alter in 3D form. 
	/// @param designatedMesh - Static mesh component 3D mesh. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *Alter;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief StatueVariables - The visual representation of this actors Budda statue in 3D form. 
	/// @param designatedMesh - Static mesh component 3D mesh. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *BuddaStatue;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief StatueVariables - The visual representation of this actors offering item in 3D form. 
	/// to be set when the player has offered item up. 
	/// @param designatedMesh - Static mesh component 3D mesh. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *OfferingItem;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief StatueVariables - Check if the player is currently overlapping the offering statue 
	/// @param overlappingSphere - USphere Component for collision. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		USphereComponent* overlappingSphere;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief StatueVariables -  required item to complete this puzzle.
	/// @param requiredItem - an Item placed in the scene. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		Item requiredItem;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief StatueVariables -  check if the item has been offered. 
	/// @param bItemOffered - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		bool bItemOffered;
	
};
