// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "Antelope.h"
#include "MainCharacter.h"
#include "AntelopeAIController.h"

AAntelopeAIController::AAntelopeAIController()
{
	PrimaryActorTick.bCanEverTick = true;

	myBlackBoardComponent = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoard Comp"));
	myBehaviourTreeComponent = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("Behaviour Comp"));


	targetLocationName = "targetLocation";
	currentEscapeWayPointName = "currentEscapePoint";
	currentRouteWayPointName = "currentRoutePoint";
	myPositionName = "myPosition";
	playerPositionName = "playerPosition";
	playerName = "player";
}

void AAntelopeAIController::Possess(APawn *p_pPawn)
{
	Super::Possess(p_pPawn);
	AAntelope* t_AICharacter = Cast<AAntelope>(p_pPawn);
	if (t_AICharacter && t_AICharacter->m_AntelopeBehaviourTree)
	{
		UBlackboardData* t_bbData = t_AICharacter->m_AntelopeBehaviourTree->BlackboardAsset;
		myBlackBoardComponent->InitializeBlackboard(*t_bbData);
		myBehaviourTreeComponent->StartTree(*t_AICharacter->m_AntelopeBehaviourTree);
	}
}


void AAntelopeAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}

void AAntelopeAIController::SetPlayer(APawn * p_pPawn)
{
	if (myBlackBoardComponent && p_pPawn)
	{
		myBlackBoardComponent->SetValueAsObject(playerName, p_pPawn);
		myBlackBoardComponent->SetValueAsVector(playerPositionName, p_pPawn->GetActorLocation());
	}
}

void AAntelopeAIController::SetRouteWaypoint(ARoutePoint * p_RoutePoint)
{
	if (myBlackBoardComponent)
	{
		myBlackBoardComponent->SetValueAsObject(currentRouteWayPointName, p_RoutePoint);
	}
}

ARoutePoint * AAntelopeAIController::GetRoutePoint()
{
	if (myBlackBoardComponent)
	{
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Emerald, FString::Printf(TEXT("Get ROUTE function")));
		return Cast<ARoutePoint>(myBlackBoardComponent->GetValueAsObject(currentRouteWayPointName));
	}
	return nullptr;
}

void AAntelopeAIController::SetEscapeWayPoint(AEscapePoint * p_EscapePoint)
{
	if (myBlackBoardComponent)
	{
		myBlackBoardComponent->SetValueAsObject(currentEscapeWayPointName, p_EscapePoint);
	}
}

AEscapePoint * AAntelopeAIController::GetEscapePoint()
{
	if (myBlackBoardComponent)
	{
		return Cast<AEscapePoint>(myBlackBoardComponent->GetValueAsObject(currentEscapeWayPointName));
	}
	return nullptr;
}

void AAntelopeAIController::SetTargetLocation(FVector  p_TargetLocation)
{
}

void AAntelopeAIController::SetMyPosition(FVector p_MyPosition)
{
	if (myBlackBoardComponent)
	{
		myBlackBoardComponent->SetValueAsVector(myPositionName, p_MyPosition);
	}
}

FVector  AAntelopeAIController::GetMyPosition()
{
	if (myBlackBoardComponent)
	{
		return myBlackBoardComponent->GetValueAsVector(myPositionName);
	}
	return FVector::ZeroVector;
}




