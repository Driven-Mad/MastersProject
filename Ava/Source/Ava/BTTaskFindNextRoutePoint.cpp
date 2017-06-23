// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "AntelopeAIController.h"
#include "RoutePoint.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "BTTaskFindNextRoutePoint.h"

EBTNodeResult::Type UBTTaskFindNextRoutePoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAntelopeAIController* MyController = Cast<AAntelopeAIController>(OwnerComp.GetAIOwner());
	if (MyController)
	{
		ARoutePoint* CurrentRoutePoint = MyController->GetRoutePoint();
		AActor* NewRoutepoint = nullptr;
		TArray<AActor*> AllRoutePoints;
		UGameplayStatics::GetAllActorsOfClass(MyController, ARoutePoint::StaticClass(), AllRoutePoints);
		float CurrentRouteNumber = CurrentRoutePoint->RouteNumber;
		CurrentRouteNumber++;
		int32 RouteZeroIndex;
		FVector MyLocation = MyController->GetMyPosition();
		/* Find a new waypoint randomly by index (this can include the current waypoint) */
		/* For more complex or human AI you could add some weights based on distance and other environmental conditions here */
		for (int32 iRouteIndex = 0; iRouteIndex < AllRoutePoints.Num(); iRouteIndex++)
		{
			ARoutePoint * tRoutePoint = Cast <ARoutePoint>(AllRoutePoints[iRouteIndex]);
			if (tRoutePoint)
			{
				if (tRoutePoint->RouteNumber == 0)
				{
					RouteZeroIndex = iRouteIndex;
				}

				if (tRoutePoint->RouteNumber == CurrentRouteNumber)
				{
					NewRoutepoint = tRoutePoint;
					break;
				}
				else
				{
					NewRoutepoint = AllRoutePoints[RouteZeroIndex];
				}
				
			}
		}

		/* Assign the new waypoint to the Blackboard */
		if (NewRoutepoint)
		{
			/* The selected key should be "CurrentWaypoint" in the BehaviorTree setup */
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), NewRoutepoint);
			return EBTNodeResult::Succeeded;
		}
		else
		{
			return EBTNodeResult::Failed;
		}
	}
	else
	{
		return EBTNodeResult::Failed;
	}
}
