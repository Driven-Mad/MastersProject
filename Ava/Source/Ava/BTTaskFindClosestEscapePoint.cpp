// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "AntelopeAIController.h"
#include "EscapePoint.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "BTTaskFindClosestEscapePoint.h"

EBTNodeResult::Type UBTTaskFindClosestEscapePoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{
	AAntelopeAIController* MyController = Cast<AAntelopeAIController>(OwnerComp.GetAIOwner());
	if (MyController)
	{
		AEscapePoint* CurrentEscapePoint = MyController->GetEscapePoint();
		AActor* NewEscapepoint = nullptr;
		TArray<AActor*> AllEscapePoints;
		UGameplayStatics::GetAllActorsOfClass(MyController, AEscapePoint::StaticClass(), AllEscapePoints);
		float Distance;
		float ShortestDistance = 0;
		int32 ShortestDistanceEscapePointIndex;
		FVector MyLocation = MyController->GetMyPosition();
		/* Find a new waypoint randomly by index (this can include the current waypoint) */
		/* For more complex or human AI you could add some weights based on distance and other environmental conditions here */
		for (int32 iEscapeIndex = 0; iEscapeIndex < AllEscapePoints.Num(); iEscapeIndex++)
		{
			Distance = (MyLocation - AllEscapePoints[iEscapeIndex]->GetActorLocation()).Size();
			if (ShortestDistance == 0 || Distance < ShortestDistance)
			{
				ShortestDistance = Distance;
				ShortestDistanceEscapePointIndex = iEscapeIndex;
			}
		}
		NewEscapepoint = AllEscapePoints[ShortestDistanceEscapePointIndex];

		/* Assign the new waypoint to the Blackboard */
		if (NewEscapepoint)
		{
			/* The selected key should be "CurrentWaypoint" in the BehaviorTree setup */
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), NewEscapepoint);
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
