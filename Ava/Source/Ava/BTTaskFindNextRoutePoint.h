//--------------------------------------------------------------------------------------------------------------------------
/// @file BTTaskFindNextRoutePoint.h
/// @brief This is a behaviour tree task which is used in UE4's behaviour system. 
/// used in my AI setup however did not make it into game. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 22/06/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once

#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTaskFindNextRoutePoint.generated.h"

/**
 * 
 */
UCLASS()
class AVA_API UBTTaskFindNextRoutePoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public: 
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:UBTTask_BlackboardBase - called as a task node on a behaviour tree. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
