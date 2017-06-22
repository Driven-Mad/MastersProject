// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "MainCharacter.h"
#include "AntelopeAIController.h"
#include "BTServiceSearchForPlayer.h"




void UBTServiceSearchForPlayer::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	
	AAntelopeAIController* MyController = Cast<AAntelopeAIController>(OwnerComp.GetAIOwner());
	if (MyController)
	{
		APawn* t_aiAntelope = MyController->GetPawn();

		if (t_aiAntelope == NULL)
		{
			return;
		}

		const FVector t_vMyLoc = t_aiAntelope->GetActorLocation();
		float t_fBestDistSq = MAX_FLT;
		AMainCharacter* t_chaBestPawn = NULL;
		for (FConstPawnIterator It = GetWorld()->GetPawnIterator(); It; ++It)
		{
			AMainCharacter* t_charTestPawn = Cast<AMainCharacter>(*It);
			if (t_charTestPawn)
			{
				const float t_fDistSq = FVector::Dist(t_charTestPawn->GetActorLocation(), t_vMyLoc);
				if (t_fDistSq < t_fBestDistSq)
				{
					t_fBestDistSq = t_fDistSq;
					t_chaBestPawn = t_charTestPawn;
				}
			}
		}
		if (t_chaBestPawn)
		{
			MyController->SetPlayer(t_chaBestPawn);
		}
	}
}