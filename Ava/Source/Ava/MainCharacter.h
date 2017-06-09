// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

UCLASS()
class AVA_API AMainCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		UCameraComponent* FollowCamera;
protected:
	void Jump() override;
	void StopJumping() override;
	void MoveForward(float value);
	void MoveRight(float value);
	void Walk();
	void StopWalking();
	void Sprint();
	void StopSprinting();
	void TurnAround();
	void StopTurning();

	void TurnCamera(float value);
	void LookUp(float value);

	void Interact();


	// Our different Charcter states. 
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsSprinting;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsRunning;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsWalking;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsJumping;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsAlert;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsTurning;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterStates)
		float walkSpeed;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterStates)
		float runSpeed;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterStates)
		float sprintSpeed;

	
};
