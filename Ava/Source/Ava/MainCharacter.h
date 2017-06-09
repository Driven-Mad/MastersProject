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
	void OpenInventory();
	void PushPull();
	void StopPushPull();



	// Our different Charcter states. 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsSprinting;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsRunning;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsWalking;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsJumping;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsAlert;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsTurning;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsIdle;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = CharacterStates)
		bool bIsInInventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float walkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float runSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float sprintSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float turnRate;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterSpeeds)
		float lookRate;
private:
	float deltaTime;
	
};
