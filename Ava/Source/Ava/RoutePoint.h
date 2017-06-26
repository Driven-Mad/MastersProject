// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/TargetPoint.h"
#include "RoutePoint.generated.h"

/**
 * 
 */
UCLASS()
class AVA_API ARoutePoint : public ATargetPoint
{
	GENERATED_BODY()
public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = RouteID)
		int RouteNumber;
	
	
};
