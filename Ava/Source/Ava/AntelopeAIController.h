// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "AIController.h"
#include "EscapePoint.h"
#include "RoutePoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AntelopeAIController.generated.h"

/**
 * 
 */
UCLASS()
class AVA_API AAntelopeAIController : public AAIController
{
	GENERATED_BODY()
public:
	AAntelopeAIController();


	//Override the parent possess 
	virtual void Possess(APawn *p_pPawn) override;
	virtual void Tick(float DeltaSeconds) override;
	//Blackboard component for the AI controller

	UPROPERTY(EditAnywhere)
		UBlackboardComponent* myBlackBoardComponent;
	//Behaviour tree component for the AI Controller
	UPROPERTY(EditAnywhere)
		UBehaviorTreeComponent* myBehaviourTreeComponent;

	//Different Names for variables within our blackboard. 
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName targetLocationName;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName currentEscapeWayPointName;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName currentRouteWayPointName;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName myPositionName;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName playerPositionName;
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName playerName;

	//Define which player
	void SetPlayer(APawn *p_pPawn);
	//Define which route waypoint
	void SetRouteWaypoint(ARoutePoint *p_RoutePoint);
	//Define which route waypoint
	void SetEscapeWayPoint(AEscapePoint * p_EscapePoint);
	void SetTargetLocation(FVector * p_TargetLocation);

	void SetMyPosition(FVector * p_MyPosition);


	//Search for player
	UFUNCTION(BlueprintCallable, Category = Behaviour)
		void SearchForPlayer();
	
	
	
};
