//--------------------------------------------------------------------------------------------------------------------------
/// @file AntelopeAIController.h
/// @brief This is our Antelope AI Controller class. It allows us to control our 
/// used in my AI setup however did not make it into game. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 12/05/17
/// Revision History:
/// No current revision history other than creation. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "AIController.h"
#include "EscapePoint.h"
#include "RoutePoint.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AntelopeAIController.generated.h"

UCLASS()
class AVA_API AAntelopeAIController : public AAIController
{
	GENERATED_BODY()
public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for Antelope AI Controller class, Sets default values for this controllers's properties
	//----------------------------------------------------------------------------------------------------------------------
	AAntelopeAIController();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AAIController - Called to possess a certain pawn.
	/// @param p_pPawn - the pawn you want possessing. 
	//---------------------------------------------------------------------------------------------------------------------- 
	virtual void Possess(APawn *p_pPawn) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AAIController - Called every frame to update the controller.
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick(float DeltaSeconds) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Blackboard component for the AI controller
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere)
		UBlackboardComponent* myBlackBoardComponent;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Behaviour tree component for the AI Controller
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere)
		UBehaviorTreeComponent* myBehaviourTreeComponent;

	//Different Names for variables within our blackboard. 
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Accessing name within our blackboard for target location
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName targetLocationName;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Accessing name within our blackboard for current escape point
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName currentEscapeWayPointName;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Accessing name within our blackboard for current route point
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName currentRouteWayPointName;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Accessing name within our blackboard for this characters position
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName myPositionName;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Accessing name within our blackboard for players position
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName playerPositionName;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Accessing name within our blackboard for the player itself.
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditDefaultsOnly, Category = "AI")
		FName playerName;

	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Define which player
	/// @param p_pPawn the pawn you want to set as the player. 
	//----------------------------------------------------------------------------------------------------------------------
	void SetPlayer(APawn *p_pPawn);

	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Define whichroute waypoint
	/// @param p_RoutePoint the Route Point you want to set as the current route point. 
	//----------------------------------------------------------------------------------------------------------------------
	void SetRouteWaypoint(ARoutePoint *p_RoutePoint);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Gets current route point. 
	/// @return returns the current route point
	//----------------------------------------------------------------------------------------------------------------------
	ARoutePoint* GetRoutePoint();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Define which escape waypoint
	/// @param p_RoutePoint the escape Point you want to set as the current escape point. 
	//----------------------------------------------------------------------------------------------------------------------
	void SetEscapeWayPoint(AEscapePoint * p_EscapePoint);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Gets current escape point
	/// @return returns the current route point
	//----------------------------------------------------------------------------------------------------------------------
	AEscapePoint* GetEscapePoint();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Define target location to move. 
	/// @param p_TargetLocation the location you want to set
	//----------------------------------------------------------------------------------------------------------------------
	void SetTargetLocation(FVector p_TargetLocation);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Define your current position. 
	/// @param p_MyPosition the position you want to set
	//----------------------------------------------------------------------------------------------------------------------
	void SetMyPosition(FVector p_MyPosition);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Gets current position
	/// @return returns the current position in Vector. 
	//----------------------------------------------------------------------------------------------------------------------
	FVector GetMyPosition();

	
};
