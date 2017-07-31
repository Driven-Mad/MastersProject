// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "MainMenu.h"


void UMainMenu::Play()
{
	UGameplayStatics::OpenLevel(UUserWidget::GetWorld(), "PalaceLevel");
	RemoveFromParent();
}
void UMainMenu::Quit()
{
	FGenericPlatformMisc::RequestExit(true);
}

void UMainMenu::NativeConstruct()
{
	Super::NativeConstruct();
}
