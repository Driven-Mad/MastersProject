// Fill out your copyright notice in the Description page of Project Settings.

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
	UFUNCTION(BlueprintCallable, Category = GameUI)
		void Play();

	virtual void NativeConstruct() override;
	//UFUNCTION(BlueprintCallable, BlueprintImplementableEvent,  Category = MyUUserWidgetClass)
	//	void Construct();
	UPROPERTY(EditAnywhere, Category = GameUI)
		AMainCharacter* playerReference;
private:
	

	
	
	
};
