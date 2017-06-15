// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DataFactory.generated.h"


//----------------------------------------------------------------------------------------------------------------------
/// @brief enums for items to be used with TMaps 
//----------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class Item : uint8 
{
	Scroll01			UMETA(DisplayName = "Scroll01"),
	Scroll02			UMETA(DisplayName = "Scroll02"),
	Scroll03			UMETA(DisplayName = "Scroll03"),
	Scroll04			UMETA(DisplayName = "Scroll04"),
	Scroll05			UMETA(DisplayName = "Scroll05"),
	Scroll06			UMETA(DisplayName = "Scroll06"),
	Scroll07			UMETA(DisplayName = "Scroll07"),
	Scroll08			UMETA(DisplayName = "Scroll08"),
	Bracelet			UMETA(DisplayName = "Bracelet")
};



//----------------------------------------------------------------------------------------------------------------------
/// @brief Data variable enums for our items to be used with TMaps 
//----------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class ItemDataVariables : uint8 
{
	itemMeshFilepath			UMETA(DisplayName = "itemMeshFilepath"),
	itemSpriteFilepath			UMETA(DisplayName = "itemSrpiteFilepath"),
	itemName					UMETA(DisplayName = "itemName"),
	itemDescription				UMETA(DisplayName = "itemDescription"),
	itemEnumIdentifier			UMETA(DisplayName = "itemEnumIdentifier")
};

typedef TMap<ItemDataVariables, FString> ItemData;


UCLASS()
class AVA_API ADataFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADataFactory();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	static TMap<Item, ItemData> Items;
	static TMap<Item, ItemData> SetupItems();

	
};
