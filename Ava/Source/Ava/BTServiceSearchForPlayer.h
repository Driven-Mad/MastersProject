//--------------------------------------------------------------------------------------------------------------------------
/// @file BTServiceSearchForPlayer.h
/// @brief This is a behaviour tree service which is used in UE4's behaviour system. 
/// used in my AI setup however did not make it into game. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 22/06/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTServiceSearchForPlayer.generated.h"

UCLASS()
class AVA_API UBTServiceSearchForPlayer : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:UBTService_BlackboardBase - called as a service node on a behaviour tree. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
protected:
private:
};
