//--------------------------------------------------------------------------------------------------------------------------
/// @file RoutePoint.h
/// @brief This is our Route point Class. It inherits from its parent class ATargetPoint.
///	@brief its a blank class mainly used to identify between different types of points 
/// @brief used in the AI part of this game that sadly has not made it to the final game due to no external environment being implemented. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 21/06/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Engine/TargetPoint.h"
#include "RoutePoint.generated.h"

UCLASS()
class AVA_API ARoutePoint : public ATargetPoint
{
	GENERATED_BODY()
public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief RouteID - Used as an identifier to choose a selected path by the artist rather than random. 
	/// @param RouteNumber -  unique identy number. 
	//----------------------------------------------------------------------------------------------------------------------
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RouteID)
		int RouteNumber;
};
