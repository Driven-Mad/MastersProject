// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Blueprint/UserWidget.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"
#include "MainCharacter.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class AVA_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
		

public:
	UFUNCTION(BlueprintCallable, Category = MyUUserWidgetClass)
		void Play();

	//UFUNCTION(BlueprintCallable, Category = MyUUserWidgetClass)
	//	void Construct();
private:
	AMainCharacter* playerReference;
	
	
};
