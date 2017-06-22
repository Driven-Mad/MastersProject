// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTServiceSearchForPlayer.generated.h"

/**
 * 
 */
UCLASS()
class AVA_API UBTServiceSearchForPlayer : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
		virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	
	
	
};
