// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Antelope.generated.h"

UCLASS()
class AVA_API AAntelope : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAntelope();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	//Collision sphere for the AI
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AIVariables)
		USphereComponent* m_CollisionSphere;

	UPROPERTY(EditAnywhere, Category = AIVariables)
		UBehaviorTree* m_AntelopeBehaviourTree;

	UPROPERTY(EditAnywhere, Category = AIVariables)
		float runningSpeed;

	UPROPERTY(EditAnywhere, Category = AIVariables)
		float walkingSpeed;


	
	
};
