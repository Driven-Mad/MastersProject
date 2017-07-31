//--------------------------------------------------------------------------------------------------------------------------
/// @file MainMenu.h
/// @brief This is our Main Menu Class. It inherits from its parent class UUserWidget.
/// We are using this class to change the menu blueprint to inherit from to save on using the blueprints themselves. 
/// @author Lloyd Phillips
/// @version 1.0
/// @date 14/06/17
/// Revision History:
/// 1st version before any revisions or user testing. 
//--------------------------------------------------------------------------------------------------------------------------
#pragma once
#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class AVA_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Called when player clicks "Play", will load up the palace level. 
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = MyUUserWidgetClass)
		void Play();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Called when player clicks "Quit", will quit the game. 
	//----------------------------------------------------------------------------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = MyUUserWidgetClass)
		void Quit();
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:UUserWidget - Called when spawned on the widget UI
	//----------------------------------------------------------------------------------------------------------------------
	virtual void NativeConstruct() override;
protected:
private:	
};
