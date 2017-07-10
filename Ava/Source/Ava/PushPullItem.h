// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "PushPullItem.generated.h"

UCLASS()
class AVA_API APushPullItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APushPullItem();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		UStaticMeshComponent *designatedMesh;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		UBoxComponent* boxCollider;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		bool constrainX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		bool constrainY;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		float xMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		float xMax;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		float yMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		float yMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		bool cappedX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
		bool cappedY;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = pushableItemVariables, meta = (AllowPrivateAccess = "true"))
	//	AMainCharacter* playerReference;
	
};
