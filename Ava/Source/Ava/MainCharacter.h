//--------------------------------------------------------------------------------------------------------------------------
/// @file MainCharacter.h
/// @brief This is our main character class. It allows us to implement movement and 
/// states of the character for manipulation in other classes
/// @author Lloyd Phillips
/// @version 1.0
/// @date 12/05/17
/// Revision History:
/// No current revision history other than creation. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once

#include "GameFramework/Character.h"
#include "PushPullItem.h"
#include "PickUpItem.h"
#include "MainCharacter.generated.h"

UCLASS()
class AVA_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for mainc character class, Sets default values for this character's properties
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
	/// @brief BeginOverlap - Tells us when this actor overlaps with another. 
	/// @param MyOverlappedActor - The actor you want to check who it overlaps with. 
	/// @param OtherActor - the actor it overlaps with. 
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = Behaviour)
		void BeginOverLap(AActor* MyOverlappedActor, AActor* OtherActor);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ExitOverLap - Tells us when this actor exits an overlap with another. 
	/// @param MyOverlappedActor - The actor you want to check who it overlaps with. 
	/// @param OtherActor - the actor it overlaps with. 
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = Behaviour)
		void ExitOverLap(AActor* MyOverlappedActor, AActor* OtherActor);

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
	/// @param bIsSprinting - is the player pressing the sprinting triggering button. This will return to false when player releases trigger
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsSprinting;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is Running
	/// @param bIsRunning - is the player running, this is set based on speed. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsRunning;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is Walking
	/// @param bIsWalking - is the player Walking, this is set based on speed && when trigger is pressed (Trigger for keyboard)
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsWalking;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is Jumping
	/// @param bIsJumping - is the player pressing the jump triggering button. This will return to false when player releases trigger
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsJumping;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is Idle
	/// @param bIsIdle - is the player not moving, this is set based on speed. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsIdle;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is In Invetory.
	/// @param bIsInInventory - has player pressed the inventory trigger, if so flip/flop between true and false. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsInInventory;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is praying
	/// @param bIsPraying - has player pressed the praying trigger. Needs to be set back to false in the animation event 
	///			via a notifier at the end of the animation.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsPraying;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is pushing/pulling
	/// @param bIsPushPulling - has player pressed the push/pull trigger. This will return to false when player releases trigger
	/// or when other conditions are met. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsPushPulling;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is intereacting
	/// @param bIsInteracting - has player pressed the interaction trigger. This will return to false when player releases trigger
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsInteracting;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Character is picking up an item
	/// @param bIsPickingUp - has player pciked up an item
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsPickingUp;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PlayerInput - Player has entered a turn left command
	/// @param bIsPlayerGoingLeft - is the player giving a command that would turn the player left. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerInput)
		bool bIsPlayerGoingLeft;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PlayerInput - Player has entered a turn right command
	/// @param bIsPlayerGoingRight - is the player giving a command that would turn the player right. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerInput)
		bool bIsPlayerGoingRight;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PlayerInput - Player has entered a go forward command
	/// @param bIsPlayerGoingForward - is the player giving a command that would move the player forward. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerInput)
		bool bIsPlayerGoingForward;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PlayerInput - Player has entered a go backward command
	/// @param bIsPlayerGoingBack - is the player giving a command that would move the player backward. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerInput)
		bool bIsPlayerGoingBack;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PlayerInput - Player has not entered any locomotion commands.
	/// @param bIsNoLocomotionInput - are NO commands for locomotion being applied.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = PlayerInput)
		bool bIsNoLocomotionInput;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PlayerInput - a value between -12 and 12 that shows the player going left/right.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = PlayerInput)
		float leftOrRightPlayer;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief PlayerInput - Player has stopped jumping
	/// @param bStopJumping - player is no longer jumping. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerInput)
		bool bStopJumping;
	
//--------------------------------------------------------------------------------------------------------------------------
/// CHARACTER SPEEDS
//--------------------------------------------------------------------------------------------------------------------------
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterSpeeds - Characters walk speed.
	/// @param walkSpeed - the speed that is applied when the character enters the bIsWalking state
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float walkSpeed;
	//----------------------------------------------------------------------------------------------------------------------
		/// @brief CharacterSpeeds - Characters run speed
		/// @param runSpeed - the speed that is applied when the character enters the bIsRunning state
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float runSpeed;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - Characters sprint speed.
	/// @param sprintSpeed - the speed that is applied when the character enters the bIsSprinting state
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float sprintSpeed;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterState - characters push and pull speed
	/// @param pushPullSpeed - the speed that is applied when the character enters the bIsPushPulling state
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float pushPullSpeed;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Camera -  The camaera boom which will stick our camera at a length from our character while also being diverse to
	/// spring back and forth depending on collision. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* CameraBoom;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Camera -  The camera that we'll be using to view our scene from. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FollowCamera;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Camera - characters camera turn speed
	/// @param turnRate - the speed the camera turns left and right with. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float turnRate;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Camera - characters camera look speed
	/// @param lookRate - the speed the camera looks up and down with. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera, meta = (AllowPrivateAccess = "true"))
		float lookRate;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Camera - camera cap for lookRate in degrees, which would stop the camera from going too far down or up. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Camera)
		float cameraDegreeCap;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterComponents - Check if the player is currently praying at the specified statue. 
	/// @param overlappingSphere - USphere Component for overlapping events. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = CharacterComponents, meta = (AllowPrivateAccess = "true"))
		USphereComponent* overlappingSphere;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterComponents - Characters push and pull trace distance
	/// @param pushPullTraceCheckDistance - the distance from the center of the actors mesh forward that the artists wish to
	/// for push and pull
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterComponents)
		float pushPullTraceCheckDistance;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterComponents - characters arm height. 
	/// @param characterArmHeight - this will increase the height that allows for the push and pull to be enabled. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterComponents)
		float characterArmHeight;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterComponents - an array that stores all the inventory objects.  
	/// @param Inventory - this array stores all the inventory objects for the player.  
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterComponents)
		TArray<Item> Inventory;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterComponents - jump delay before jump is played. 
	/// @param jumpDelay - this will delay the jump
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterComponents)
		float jumpDelay;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterComponents - Will allow us to play our timeline via a curve.
	/// @param RunToIdleTimeline - pointer to a timeline component. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CharacterComponents)
		UTimelineComponent* RunToIdleTimeline;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterComponents - Will allow us to play our timeline via a curve.
	/// @param SprintToIdleTimeline - pointer to a timeline component. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY( EditAnywhere, BlueprintReadOnly, Category = CharacterComponents)
		UTimelineComponent* SprintToIdleTimeline;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterComponents -  The curve for the Run to Idle timeline. Must go from 0 -> 1
	/// @param RunToIdleCurve - curve designated by artist. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CharacterComponents)
		UCurveFloat* RunToIdleCurve;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief CharacterComponents -  The curve for the Sprint to Idle timeline. Must go from 0 -> 1
	/// @param SprintToIdleCurve - curve designated by artist. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = CharacterComponents)
		UCurveFloat* SprintToIdleCurve;
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
	/// @brief bool to make sure that the play is only played once at a time, not over and over. on Run To Idle
	//----------------------------------------------------------------------------------------------------------------------
	bool playOnceRunToIdle;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief bool to make sure that the play is only played once at a time, not over and over. 
	//----------------------------------------------------------------------------------------------------------------------
	bool playOnceSprintToIdle;


	//----------------------------------------------------------------------------------------------------------------------
	/// @brief boolean so we know when to show the access inventory Icon on the UI
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterUIComponents)
		bool bAccessInventoryUI;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief boolean so we know when to show the psh and pul Icon on the UI
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterUIComponents)
		bool bPushAndPullUI;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief boolean so we know when to show the Interact Icon on the UI
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterUIComponents)
		bool bInteractUI;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief boolean so we know when to show the Interact Icon on the UI
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterUIComponents)
		bool bInteractStatueUI;

private:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Deltatime to be used anywhere. 
	//----------------------------------------------------------------------------------------------------------------------
	float deltaTime;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Deltatime to be used anywhere. 
	//----------------------------------------------------------------------------------------------------------------------
	FVector ForwardVector;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Deltatime to be used anywhere. 
	//----------------------------------------------------------------------------------------------------------------------
	FVector BackVector;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Deltatime to be used anywhere. 
	//----------------------------------------------------------------------------------------------------------------------
	FVector RightVector;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Deltatime to be used anywhere. 
	//----------------------------------------------------------------------------------------------------------------------
	FVector LeftVector;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Deltatime to be used anywhere. 
	//----------------------------------------------------------------------------------------------------------------------
	APushPullItem* attachedPushPullItem;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Deltatime to be used anywhere. 
	//----------------------------------------------------------------------------------------------------------------------
	float storedLookRate;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Deltatime to be used anywhere. 
	//----------------------------------------------------------------------------------------------------------------------
	float storedturnRate;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Deltatime to be used anywhere. 
	//----------------------------------------------------------------------------------------------------------------------
	bool bPushPullColliding;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief timer delay for jump. 
	//----------------------------------------------------------------------------------------------------------------------
	float jumpDelayTimer;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief if jump timer should be started.  
	//----------------------------------------------------------------------------------------------------------------------
	bool startTimer;

	//----------------------------------------------------------------------------------------------------------------------
	/// @brief timer for sprint Set amount.
	//----------------------------------------------------------------------------------------------------------------------
	float sprintTimerAmount;
};
