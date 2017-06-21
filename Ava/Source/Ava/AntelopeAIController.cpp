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
	currentEscapeWayPointName = "currentEscapeWayPoint";
	currentRouteWayPointName = "currentRouteWayPoint";
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

void AAntelopeAIController::SetEscapeWayPoint(AEscapePoint * p_EscapePoint)
{
	if (myBlackBoardComponent)
	{
		myBlackBoardComponent->SetValueAsObject(currentEscapeWayPointName, p_EscapePoint);

	}
}

void AAntelopeAIController::SetTargetLocation(FVector * p_TargetLocation)
{
}

void AAntelopeAIController::SetMyPosition(FVector * p_MyPosition)
{
}

void AAntelopeAIController::SearchForPlayer()
{
	APawn* t_aiAntelope = GetPawn();

	if (t_aiAntelope == NULL)
	{
		return;
	}

	const FVector t_vMyLoc = t_aiAntelope->GetActorLocation();
	float t_fBestDistSq = MAX_FLT;
	AMainCharacter* t_chaBestPawn = NULL;
	for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
	{
		AMainCharacter* t_charTestPawn = Cast<AMainCharacter>(*It);
		if (t_charTestPawn)
		{
			const float t_fDistSq = FVector::Dist(t_charTestPawn->GetActorLocation(), t_vMyLoc);
			if (t_fDistSq < t_fBestDistSq)
			{
				t_fBestDistSq = t_fDistSq;
				t_chaBestPawn = t_charTestPawn;
			}
		}
	}
	if (t_chaBestPawn)
	{
		SetPlayer(t_chaBestPawn);
	}
}



