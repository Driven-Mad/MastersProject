//--------------------------------------------------------------------------------------------------------------------------
/// @file OfferingPit.h
/// @brief This is our Offering Pit class, to be used within the red room puzzle.  
/// @author Lloyd Phillips
/// @version 1.0
/// @date 25/06/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once

#include "GameFramework/Actor.h"
#include "DataFactory.h"
#include "OfferingPit.generated.h"

UCLASS()
class AVA_API AOfferingPit : public AActor
{
	GENERATED_BODY()
	
public:	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for offering item class, Sets default values for this actors properties
	//----------------------------------------------------------------------------------------------------------------------
	AOfferingPit();
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
	/// @brief StatueVariables - The visual representation of this actor in 3D form. 
	/// @param designatedMesh - Static mesh component 3D mesh. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = OfferingPitVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *offeringPitMesh;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief OfferingPitVariables - Check if the player is currently overlapping the offering statue 
	/// @param overlappingSphere - USphere Component for collision. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = OfferingPitVariables, meta = (AllowPrivateAccess = "true"))
		USphereComponent* overlappingSphere;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief OfferingPitVariables -  required item to complete this puzzle.
	/// @param requiredItem - an Item placed in the scene. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = OfferingPitVariables, meta = (AllowPrivateAccess = "true"))
		Item requiredItem;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief OfferingPitVariables -  check if the item has been offered. 
	/// @param bItemOffered - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = OfferingPitVariables, meta = (AllowPrivateAccess = "true"))
		bool bItemOffered;
};
