//--------------------------------------------------------------------------------------------------------------------------
/// @file DataFactory.h
/// @brief This is our data factory class, used to store and distribute data to the game. Mainly used for items currently. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 13/06/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "GameFramework/Actor.h"
#include "DataFactory.generated.h"

//----------------------------------------------------------------------------------------------------------------------
/// @brief enums for items to be used with TMaps 
//----------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class Item : uint8 
{
	BLANK				UMETA(DisplayName = "BLANK"),
	Scroll01			UMETA(DisplayName = "Scroll01"),
	Scroll02			UMETA(DisplayName = "Scroll02"),
	Scroll03			UMETA(DisplayName = "Scroll03"),
	Scroll04			UMETA(DisplayName = "Scroll04"),
	Scroll05			UMETA(DisplayName = "Scroll05"),
	Scroll06			UMETA(DisplayName = "Scroll06"),
	Scroll07			UMETA(DisplayName = "Scroll07"),
	Scroll08			UMETA(DisplayName = "Scroll08"),
	Bracelet			UMETA(DisplayName = "Bracelet"),
	Item01				UMETA(DisplayName = "Item01"),
	Item02				UMETA(DisplayName = "Item02"),
	Item03				UMETA(DisplayName = "Item03"),
	Trash01				UMETA(DisplayName = "Trash01"),
	Trash02				UMETA(DisplayName = "Trash02"),
	Trash03				UMETA(DisplayName = "Trash03"),
	Trash04				UMETA(DisplayName = "Trash04")
};

//----------------------------------------------------------------------------------------------------------------------
/// @brief Data variable enums for our items to be used with TMaps 
//----------------------------------------------------------------------------------------------------------------------
UENUM(BlueprintType)
enum class ItemDataVariables : uint8 
{
	itemMeshFilepath			UMETA(DisplayName = "itemMeshFilepath"),
	itemSpriteFilepath			UMETA(DisplayName = "itemSrpiteFilepath"),
	itemSelectedSpriteFilepath	UMETA(DisplayName = "itemSrpiteFilepath"),
	itemName					UMETA(DisplayName = "itemName"),
	itemDescription				UMETA(DisplayName = "itemDescription"),
	itemEnumIdentifier			UMETA(DisplayName = "itemEnumIdentifier")
};
//----------------------------------------------------------------------------------------------------------------------
/// @brief define our map to allow a map of maps. making it a data type.
//----------------------------------------------------------------------------------------------------------------------
typedef TMap<ItemDataVariables, FString> ItemData;


UCLASS()
class AVA_API ADataFactory : public AActor
{
	GENERATED_BODY()
	
public:	
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief ctor for data factory class, Sets default values for this actors properties
	//----------------------------------------------------------------------------------------------------------------------
	ADataFactory();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called when the game starts or when spawned for our data factory
	//----------------------------------------------------------------------------------------------------------------------
	virtual void BeginPlay() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:AActor - Called every frame to update the data factory
	/// @param DeltaSeconds - Delta time, the time between frame updates. 
	//----------------------------------------------------------------------------------------------------------------------
	virtual void Tick(float DeltaSeconds) override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Called when you need to access the maps data variables 
	/// @param Item_type - The item that you want to look up.
	/// @param Item_variable - The ItemDataVariables that you want to look up.
	/// @return returns a string containing the information OF Item_Type, and the vraible Item_
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = "Items")
		FString AccessTMapItems(Item Item_type, ItemDataVariables Item_variable);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Called when you need to get the 3D mesh for Item_Type.
	/// @param Item_type - The item that you want to look up.
	/// @return returns the static mesh of the item Item_Type
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = "Items")
		UStaticMesh* Get3DRepresentationForItem(Item Item_type);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Called when you need to get the Item_Type 2D Icon (Normal)
	/// @param Item_type - The item that you want to look up.
	/// @return returns the texture for the icon of the item Item_Type
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = "Items")
		UTexture2D* GetIconForItem(Item Item_type);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Called when you need to get the Item_Type 2D Icon (Hovered)
	/// @param Item_type - The item that you want to look up.
	/// @return returns the texture for the icon of the item Item_Type
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = "Items")
		UTexture2D* GetIconSelectedForItem(Item Item_type);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Called when you need to get the Item based on a string type and name. 
	/// @param enumType - The enum that you want to look up.
	/// @param enumName - The item that you want to look up.
	/// @return returns the items discription in a string. 
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = "Items")
		Item GetItemType(const FString &enumType, const FString &enumName);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Called when you need to get the Item_Type description
	/// @param Item_type - The item that you want to look up.
	/// @return returns the items discription in a string. 
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = "Items")
		FString getItemDescription(Item ItemToSpawn);
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief called to set up the items data variables. 
	/// @return returns a map of maps that we use to set up our items with. 
	//----------------------------------------------------------------------------------------------------------------------
	static TMap<Item, ItemData> SetupItems();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief our accessor for all our items, the map of maps. 
	//----------------------------------------------------------------------------------------------------------------------
	static TMap<Item, ItemData> Items;
	
};
