// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "MainGameUI.h"


void UMainGameUI::NativeConstruct()
{
	Super::NativeConstruct();
	playerReference = Cast<AMainCharacter>(UGameplayStatics::GetPlayerController(UUserWidget::GetWorld(), 0));
	//playerReference = Cast<AMainCharacter>( GetOwningPlayer());
}

