// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "MainMenu.h"


void UMainMenu::Play()
{
	UGameplayStatics::OpenLevel(UUserWidget::GetWorld(), "PalaceLevel");
	RemoveFromParent();
}

//void UMainMenu::Construct()
//{
//	playerReference = Cast<AMainCharacter>(UGameplayStatics::GetPlayerController(UUserWidget::GetWorld(), 0));
//	//playerReference = Cast<AMainCharacter>( GetOwningPlayer());
//}
