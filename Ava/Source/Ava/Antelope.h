//--------------------------------------------------------------------------------------------------------------------------
/// @file Antelope.h
/// @brief This is our Antelope class. It allows us to implement movement and behaviour of our antelope.
/// used in my AI setup however did not make it into game. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 12/05/17
/// Revision History:
/// No current revision history other than creation. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Antelope.generated.h"

UCLASS()
class AVA_API AAntelope : public ACharacter
{
	GENERATED_BODY()

public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for our antelope class, Sets default values for this character's properties
	//----------------------------------------------------------------------------------------------------------------------
	AAntelope();	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:ACharacter - Called when the game starts or when spawned for our character.
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:ACharacter - Called every frame to update the character.
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick(float DeltaSeconds) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:ACharacter - Sets up and links the character functions to mappings of the projects controls. .
	/// @param InputComponent - The input component for this class. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief AIVariables - Check if the player is currently praying at the specified statue. 
	/// @param overlappingSphere - USphere Component for overlapping events. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AIVariables)
		USphereComponent* m_CollisionSphere;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief AIVariables - controls the behaviour of this character. 
	/// @param m_AntelopeBehaviourTree - the behaviour tree assosicated with the character. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, Category = AIVariables)
		UBehaviorTree* m_AntelopeBehaviourTree;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief AIVariables - Antelopes run speed
	/// @param runningSpeed - the speed that is applied when the Antelopes enters the running state
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, Category = AIVariables)
		float runningSpeed;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief AIVariables - Antelopes walk speed
	/// @param walkingSpeed - the speed that is applied when the Antelopes enters the walking state
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, Category = AIVariables)
		float walkingSpeed;	
};
