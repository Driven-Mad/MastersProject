//--------------------------------------------------------------------------------------------------------------------------
/// @file EscapePoint.h
/// @brief This is our Escape point Class. It inherits from its parent class ATargetPoint.
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
#include "EscapePoint.generated.h"

UCLASS()
class AVA_API AEscapePoint : public ATargetPoint
{
	GENERATED_BODY()
};
