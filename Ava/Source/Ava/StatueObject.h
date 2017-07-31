//--------------------------------------------------------------------------------------------------------------------------
/// @file StatueObject.h
/// @brief This is our Statue Object Class. It inherits from its parent class AActor.
/// @brief Used as the actor that the character will pray at to get hints throughout the game. 
/// and is used within every single puzzle
/// @author Lloyd Phillips
/// @version 1.0
/// @date 15/06/17
/// Revision History:
/// 1st version before any user testing or bug fixes. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "GameFramework/Actor.h"
#include "MainCharacter.h"
#include "StatueObject.generated.h"

UCLASS()
class AVA_API AStatueObject : public AActor
{
	GENERATED_BODY()
	
public:	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for statue objects, Sets default values for the actor.
	//----------------------------------------------------------------------------------------------------------------------
	AStatueObject();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called when the game starts or when spawned.
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief StatueVariables - The visual representation of this actor in 3D form. 
	/// @param designatedMesh - Static mesh component 3D mesh. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *designatedMesh;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief StatueVariables - Name of the staue - Which room its in
	/// @param statueName - Used for debugging. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		FString statueName;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief StatueVariables - Check if the player is currently praying at the specified statue. 
	/// @param overlappingSphere - USphere Component for collision. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		USphereComponent* overlappingSphere;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief StatueVariables - Check if the player is currently praying at the specified statue. 
	/// @param isPlayerPraying - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		bool isPlayerPraying;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief StatueVariables - Check if the player can play at this current statue. 
	/// @param bCanPlayerPray - boolean check. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = StatueVariables, meta = (AllowPrivateAccess = "true"))
		bool bCanPlayerPray;
protected:
private:

};
