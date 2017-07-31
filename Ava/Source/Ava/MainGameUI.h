//--------------------------------------------------------------------------------------------------------------------------
/// @file MainGameUI.h
/// @brief This is our Main Game UI Class. It inherits from its parent class UUserWidget.
/// We are using this class to alter the UI in game through code if necessary.
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
#include "MainCharacter.h"
#include "MainGameUI.generated.h"

/**
 * 
 */
UCLASS()
class AVA_API UMainGameUI : public UUserWidget
{
	GENERATED_BODY()
public:
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief Overridden:UUserWidget - Called when spawned on the widget UI
	//----------------------------------------------------------------------------------------------------------------------
	virtual void NativeConstruct() override;
	//----------------------------------------------------------------------------------------------------------------------
	/// @brief GameUI - Player reference to be used within the functions of this class. 
	/// @param playerReference - Player pointer. 
	//----------------------------------------------------------------------------------------------------------------------
	UPROPERTY(EditAnywhere, Category = GameUI)
		AMainCharacter* playerReference;
protected:
private:	
};
