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
		GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Emerald, FString::Printf(TEXT("I'm in the if statement controller")));
		AActor* CurrentRoutePoint = MyController->GetRoutePoint();
		AActor* NewRoutepoint = nullptr;
		TArray<AActor*> AllRoutePoints;
		UGameplayStatics::GetAllActorsOfClass(MyController, ARoutePoint::StaticClass(), AllRoutePoints);
		if (CurrentRoutePoint)
		{
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Emerald, FString::Printf(TEXT("I'm in the if statement nullptr")));
			ARoutePoint *temp = Cast<ARoutePoint>(CurrentRoutePoint);
			int CurrentRouteNumber = temp->RouteNumber;
			CurrentRouteNumber = CurrentRouteNumber + 1;
			int32 RouteZeroIndex = 0;

			for (int32 iRouteIndex = 0; iRouteIndex < AllRoutePoints.Num(); iRouteIndex++)
			{
				ARoutePoint *tRoutePoint = Cast <ARoutePoint>(AllRoutePoints[iRouteIndex]);
				if (tRoutePoint)
				{
					GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Emerald, FString::Printf(TEXT("I'm in the if statement ")));
					if (tRoutePoint->RouteNumber == 0)
					{
						RouteZeroIndex = iRouteIndex;
					}

					if (tRoutePoint->RouteNumber == CurrentRouteNumber)
					{
						NewRoutepoint = AllRoutePoints[iRouteIndex];
					}

				}
			}

		}
		else
		{
			NewRoutepoint = AllRoutePoints[0];
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
