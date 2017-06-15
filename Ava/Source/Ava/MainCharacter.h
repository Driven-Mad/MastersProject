// Fill out your copyright notice in the Description page of Project Settings.
//--------------------------------------------------------------------------------------------------------------------------
/// @file MainCharacter.h
/// @brief This is our main character class. It allows us to implement movement and 
/// states of the character for manipulation in other classes
/// @author Lloyd Phillips
/// @version 0.3
/// @date 12/05/17
/// Revision History:
/// Currently in working progress, Controller is workingish. Need to implement a few other things. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once

#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class AVA_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for turtle class, Sets default values for this character's properties
	//----------------------------------------------------------------------------------------------------------------------
	AMainCharacter();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:ACharacter - Called when the game starts or when spawned for our character.
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:ACharacter - Called every frame to update the character.
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick( float DeltaSeconds ) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:ACharacter - Sets up and links the character functions to mappings of the projects controls. .
	/// @param InputComponent - The input component for this class. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief The camaera boom which will stick our camera at a length from our character while also being diverse to
	/// spring back and forth depending on collision. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* CameraBoom;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief The camera that we'll be using to view our scene from. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FollowCamera;

protected:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:ACharacter - Called when the player presses appropriate input to Jump. 
	//----------------------------------------------------------------------------------------------------------------------
	void Jump() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:ACharacter - Called when the player unpresses appropriate input to jump. 
	//----------------------------------------------------------------------------------------------------------------------
	void StopJumping() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to move our character component Forward and Back.
	/// @param value - refers to the axis mapping given through the input window of project settings (either 0,1,-1,)
	//----------------------------------------------------------------------------------------------------------------------
	void MoveForward(float value);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to move our character component left and Right.
	/// @param value - refers to the axis mapping given through the input window of project settings (either 0,1,-1,)
	//----------------------------------------------------------------------------------------------------------------------
	void MoveRight(float value);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to switch too walk mode.
	//----------------------------------------------------------------------------------------------------------------------
	void Walk();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to stop walk mode.
	//----------------------------------------------------------------------------------------------------------------------
	void StopWalking();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to switch too Sprint mode.
	//----------------------------------------------------------------------------------------------------------------------
	void Sprint();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to stop Sprint mode.
	//----------------------------------------------------------------------------------------------------------------------
	void StopSprinting();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to turn around 180 degrees. (WIP)
	//----------------------------------------------------------------------------------------------------------------------
	void TurnAround();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to stop turning (WIP)
	//----------------------------------------------------------------------------------------------------------------------
	void StopTurning();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to turn the camera. 
	/// @param value - refers to the axis mapping given through the input window of project settings (either 0,1,-1,)
	//----------------------------------------------------------------------------------------------------------------------
	void TurnCamera(float value);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to look up with the camera. 
	/// @param value - refers to the axis mapping given through the input window of project settings (either 0,1,-1,)
	//----------------------------------------------------------------------------------------------------------------------
	void LookUp(float value);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to allow the character to interact with an item/object/puzzle etc. (WIP)
	//----------------------------------------------------------------------------------------------------------------------
	void Interact();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to allow the character to interact with an item/object/puzzle etc. (WIP)
	//----------------------------------------------------------------------------------------------------------------------
	void StopInteract();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to toggle opening/closing the inventory system (WIP)
	//----------------------------------------------------------------------------------------------------------------------
	void OpenInventory();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Function to attach and go into push and pull mode. 
	//----------------------------------------------------------------------------------------------------------------------
	void PushPull();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief  Function to detach and go out of push and pull mode. 
	//----------------------------------------------------------------------------------------------------------------------
	void StopPushPull();
public:
//--------------------------------------------------------------------------------------------------------------------------
/// CHARACTER STATES
//--------------------------------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is Sprinting
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsSprinting;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is Running
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsRunning;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is Walking
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsWalking;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is Jumping
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsJumping;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is Alert
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsAlert;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is Turning
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsTurning;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is Idle
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsIdle;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is In Invetory.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsInInventory;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is praying
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsPraying;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is pushing/pulling
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsPushPulling;

	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is pushing/pulling
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsInteracting;

	
//--------------------------------------------------------------------------------------------------------------------------
/// CHARACTER SPEEDS
//--------------------------------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterSppeds - Characters walk speed.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float walkSpeed;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterSppeds - Characters run speed.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float runSpeed;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Characters sprint speed.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float sprintSpeed;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - characters camera turn speed
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float turnRate;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - characters camera look speed
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float lookRate;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = prayingComponents, meta = (AllowPrivateAccess = "true"))
		USphereComponent* overlappingSphere;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float pushPullTraceCheckDistance;

	FVector ForwardVector;
	FVector BackVector;
	FVector RightVector;
	FVector LeftVector;

private:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Deltatime to be used anywhere. 
	//----------------------------------------------------------------------------------------------------------------------
	float deltaTime;
	


};
