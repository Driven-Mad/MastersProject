// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "StatueObject.h"
#include "MainCharacter.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	walkSpeed = 50;
	runSpeed = 150;
	sprintSpeed = 350;
	lookRate = 45;
	turnRate = 45;
	pushPullSpeed = 75;
	bIsNoLocomotionInput = true;
	bIsPlayerGoingRight = false;
	bIsPlayerGoingLeft = false;
	bIsPlayerGoingForward = false;
	bIsPlayerGoingBack = false;

	cameraDegreeCap = 15.0f;

	bIsInInventory = false;
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);
	SetRootComponent(GetCapsuleComponent());


	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 300.f;
	GetCharacterMovement()->AirControl = 0.2f;
	GetCharacterMovement()->MaxWalkSpeed = runSpeed;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	//** DEPRECATED NEEDS CHANGING : AttachToComponent**
	CameraBoom->AttachTo(RootComponent);
	CameraBoom->SocketOffset = FVector(0, 0, 70);
	CameraBoom->TargetArmLength = 200.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
	CameraBoom->bDoCollisionTest = true;



	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	//** DEPRECATED NEEDS CHANGING : AttachToComponent**
	FollowCamera->AttachTo(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
	
	//FollowCamera->PostProcessSettings.AutoExposureBias = 0.f;
	//FollowCamera->PostProcessSettings.AutoExposureMinBrightness = 1.f;
	//FollowCamera->PostProcessSettings.AutoExposureMaxBrightness = 1.f;

	overlappingSphere = CreateDefaultSubobject<USphereComponent>(TEXT("overlappingSphere"));
	overlappingSphere->SetSphereRadius(100.f);
	overlappingSphere->AttachTo(RootComponent);
	
	OnActorBeginOverlap.AddDynamic(this, &AMainCharacter::BeginOverLap);
	OnActorEndOverlap.AddDynamic(this, &AMainCharacter::ExitOverLap);
	
	bIsIdle = true;
	bIsRunning = false;
	bIsPraying = false;
	bIsInInventory = false;
	bIsJumping = false;
	bPushPullColliding = false;
	bIsPushPulling = false;
	bIsPickingUp = false;
	jumpDelay = 0;
	jumpDelayTimer = 0;
	bStopJumping = false;
	playOnceRunToIdle = false;
	playOnceSprintToIdle = false;

	static ConstructorHelpers::FObjectFinder<UCurveFloat> Curvy(TEXT("/Game/TemporaryContent/RunToIdleCurve.RunToIdleCurve"));
	if (Curvy.Object)
	{
		RunToIdleCurve = Curvy.Object;
		RunToIdleTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineRunToIdle"));
	
		//Bind the Callbackfuntion for the float return value
		InterpFunction.BindUFunction(this, FName{ TEXT("TimelineFloatReturn") });
	}
	
	static ConstructorHelpers::FObjectFinder<UCurveFloat> Curvy2(TEXT("/Game/TemporaryContent/SprintToIdleCurve.SprintToIdleCurve"));
	if (Curvy2.Object)
	{
		SprintToIdleCurve = Curvy2.Object;
		SprintToIdleTimeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("TimelineSprintToIdle"));
	}
}


void AMainCharacter::BeginOverLap(AActor* MyOverlappedActor, AActor* OtherActor)
{
	if (bIsPushPulling)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("StartedOverlapping")));
		bPushPullColliding = true;
	}
}

void AMainCharacter::ExitOverLap(AActor* MyOverlappedActor, AActor* OtherActor)
{
	if (bIsPushPulling)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("ExitOverLap")));
		bPushPullColliding = false;
	}
}


// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	jumpDelayTimer = jumpDelay;

	RunToIdleTimeline->AddInterpFloat(RunToIdleCurve, InterpFunction, FName{ TEXT("Floaty") });
	SprintToIdleTimeline->AddInterpFloat(SprintToIdleCurve, InterpFunction, FName{ TEXT("Floaty2") });
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	deltaTime = DeltaTime;
	float speed = GetVelocity().Size();
	if (!bIsPlayerGoingBack && !bIsPlayerGoingForward && !bIsPlayerGoingLeft && !bIsPlayerGoingRight)
	{
		bIsNoLocomotionInput = true;
		if (!RunToIdleTimeline->IsPlaying() && speed !=0 && !playOnceRunToIdle && GetCharacterMovement()->MaxWalkSpeed <= runSpeed && GetCharacterMovement()->MaxWalkSpeed > walkSpeed)
		{
			RunToIdleTimeline->PlayFromStart();
			playOnceRunToIdle = true;
		}
		//SprintToIdleTimeline
	
		if (GetCharacterMovement()->MaxWalkSpeed > runSpeed && !SprintToIdleTimeline->IsPlaying() && speed != 0 && !playOnceSprintToIdle)
		{
			
			SprintToIdleTimeline->PlayFromStart();
			playOnceSprintToIdle = true;
			
		}
		
		
	}
	else
	{
		//SprintToIdleTimeline->Stop();
		//RunToIdleTimeline->Stop();
		//GetCharacterMovement()->MaxWalkSpeed = runSpeed;
		//LEFT AND RIGHT?
		playOnceRunToIdle = false;
		playOnceSprintToIdle = false;
		bIsNoLocomotionInput = false;
		
		
	}
	//For Controller:
	
	if (speed == 0)
	{
		bIsIdle = true;
		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Purple, "I'M IDLE");
	}
	else if (speed <= walkSpeed)
	{
		bIsWalking = true;
		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Purple, "I'M WALKING");
	}
	else if (speed < sprintSpeed && speed >= runSpeed)
	{
		bIsRunning = true;
		bIsWalking = false;
	}else
	{
		bIsRunning = false;
		bIsWalking = false;
	}
	if (Controller != NULL)
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation = FRotator(0, Rotation.Yaw, 0);
		ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		BackVector = -ForwardVector;
		LeftVector = -RightVector;
		FRotator tempRot = GetActorRotation();
		FRotator tempYaw = FRotator(0, tempRot.Yaw, 0);
		FVector tempFV = FRotationMatrix(tempYaw).GetUnitAxis(EAxis::X);
		FVector tempActorLocation = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z+ characterArmHeight);
		FVector end = (tempActorLocation + (tempFV * pushPullTraceCheckDistance));
		DrawDebugLine(
			GetWorld(),
			tempActorLocation,
			end,
			FColor(0, 255, 0),
			false, -1, 0,
			5.f
		);
	}
	if (bIsPushPulling)
	{
		if (attachedPushPullItem)
		{
			if (attachedPushPullItem->cappedX == true)
			{
				StopPushPull();
				attachedPushPullItem->cappedX = false;
			}
			if (attachedPushPullItem->cappedY == true)
			{
				StopPushPull();
				attachedPushPullItem->cappedY = false;
			}
		}

	}
	//! EVEN with just adjusting the position the collision is STILL ignored.
	//if (bIsPushPulling)
	//{
	//	float distance = (GetActorLocation() - attachedPushPullItem->GetActorLocation()).Size();
	//	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, FString::Printf(TEXT("Distance is: %f"), distance));
	//	FVector Direction = (attachedPushPullItem->GetActorLocation() - GetActorLocation());
	//	Direction.Normalize();
	//	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, FString::Printf(TEXT("X is: %f, Y is: %f, Z is: %f"), Direction.X, Direction.Y, Direction.Z));
	//	FVector newLocation = GetActorLocation() + Direction;
	//	newLocation.Z = attachedPushPullItem->GetActorLocation().Z;
	//	DrawDebugLine(
	//		GetWorld(),
	//		GetActorLocation(),
	//		newLocation,
	//		FColor(255, 0, 0),
	//		false, -1, 0,
	//		3.f
	//	);
	//	//FVector newLocation = GetActorLocation() + (Forward * distance);
	//	//newLocation.Z = attachedPushPullItem->GetActorLocation().Z;
	//	attachedPushPullItem->SetActorLocation(newLocation);
	//}
	if (jumpDelay != 0.f && startTimer)
	{
		jumpDelayTimer -= (deltaTime);
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, FString::Printf(TEXT("camera: %f"), jumpDelayTimer));
	}

	if (!bIsPraying && jumpDelayTimer <= 0.f && startTimer)
	{
		Super::Jump();
		jumpDelayTimer = jumpDelay;
		startTimer = false;
	}
	if (Controller)
	{
		//leftOrRightPlayer = FVector::DotProduct(Controller->GetActorForwardVector(), Controller->GetVelocity());


		//gives + 16 on both left and right, 148 forward, -148 backwards, 148 with camera + movement.
		//leftOrRightPlayer = FVector::DotProduct(Controller->GetActorForwardVector(), GetVelocity());

		// -149 left, 149 right, Camera: + left, - right, 0 forward.
		//leftOrRightPlayer = FVector::DotProduct(Controller->GetActorRightVector(), GetVelocity());

		//gives + 16 on both left and right, 148 forward, -148 backwards, 148 with camera + movement.
		//leftOrRightPlayer = FVector::DotProduct(Controller->GetActorForwardVector(), GetCapsuleComponent()->GetComponentVelocity());

		//1 everywhere
		//leftOrRightPlayer = FVector::DotProduct(Controller->GetActorRightVector(), FollowCamera->GetRightVector());

		// -149 left, 149 right, Camera: + left, - right, 0 forward.
		//leftOrRightPlayer = FVector::DotProduct(FollowCamera->GetRightVector(), GetVelocity());

		//gives + 16 on both left and right, 148 forward, -148 backwards, 148 with camera + movement.
		//leftOrRightPlayer = FVector::DotProduct(FollowCamera->GetForwardVector(), GetVelocity());

		//Gives 150 on each axis
		//leftOrRightPlayer = FVector::DotProduct(GetActorForwardVector(), GetVelocity());

		//Gives you up to -12 Left, 12 right, 0 forward and backwards. Depending of speed of camera turn, gives negative left, positive right. !!! THIS ONE SO FAR !!!
		leftOrRightPlayer = (FVector::DotProduct(GetActorRightVector(), GetVelocity()));

		//gives + 16 on both left and right, 148 forward, -148 backwards, 148 with camera + movement.
		//leftOrRightPlayer = FVector::DotProduct(GetCapsuleComponent()->GetComponentVelocity(), Controller->GetActorForwardVector()); 

		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, FString::Printf(TEXT("camera: %f"), leftOrRightPlayer));
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

	//Bind Jump Functionalities to input mapping "Jump"
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMainCharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMainCharacter::StopJumping);

	//Bind Sprint Functionalities to input mapping "Sprint"
	InputComponent->BindAction("Sprint", IE_Pressed, this, &AMainCharacter::Sprint);
	InputComponent->BindAction("Sprint", IE_Released, this, &AMainCharacter::StopSprinting);

	//Bind Walk Functionalities to input mapping "Walk"
	InputComponent->BindAction("Walk", IE_Pressed, this, &AMainCharacter::Walk);
	InputComponent->BindAction("Walk", IE_Released, this, &AMainCharacter::StopWalking);

	//Bind Push/Pull Functionalities to input mapping "PushPull"
	InputComponent->BindAction("PushPull", IE_Pressed, this, &AMainCharacter::PushPull);

	//Bind open/Close Inventory Functionalities to input mapping "Inventory"
	InputComponent->BindAction("Inventory", IE_Pressed, this, &AMainCharacter::OpenInventory);

	//Bind open/Close Inventory Functionalities to input mapping "Interact"
	InputComponent->BindAction("Interact", IE_Pressed, this, &AMainCharacter::Interact);
	InputComponent->BindAction("Interact", IE_Released, this, &AMainCharacter::StopInteract);

	//Bind our axis inputs for movement.
	InputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);

	InputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);

	InputComponent->BindAxis("Turn", this, &AMainCharacter::TurnCamera);
	InputComponent->BindAxis("LookUp", this, &AMainCharacter::LookUp);




	InputComponent->BindAction("TurnAround", IE_Pressed, this, &AMainCharacter::TurnAround);
}

void AMainCharacter::Jump()
{
	if (!bStopJumping && !bIsPushPulling && !bIsJumping)
	{
		bIsJumping = true;
		startTimer = true;

		jumpDelayTimer = jumpDelay;
	}
	
	
}

void AMainCharacter::StopJumping()
{
	Super::StopJumping();
	bIsJumping = false;
}

void AMainCharacter::MoveForward(float value)
{

	if ((Controller != NULL) && (value != 0.0f) && !bPushPullColliding && !bIsPraying && !bIsPushPulling)
	{
		if (!bIsWalking && !bIsIdle && !bIsSprinting)
		{
			SprintToIdleTimeline->Stop();
			RunToIdleTimeline->Stop();
			GetCharacterMovement()->MaxWalkSpeed = runSpeed;
		}
		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Purple, "I'M RUNNING");
		AddMovementInput(ForwardVector, value);
		if (value > 0.0)
		{
			//Moving forward
			bIsPlayerGoingForward = true;
			bIsPlayerGoingBack = false;
		}
		if (value < 0.0)
		{
			//Moving backward
			bIsPlayerGoingForward = false;
			bIsPlayerGoingBack = true;
		}
	}
	if (value == 0.0f)
	{
		bIsPlayerGoingForward = false;
		bIsPlayerGoingBack = false;
	}

	if (bIsPushPulling)
	{
		FRotator tempRot = GetActorRotation();
		FRotator tempYaw = FRotator(0, tempRot.Yaw, 0);
		FVector tempFV = FRotationMatrix(tempYaw).GetUnitAxis(EAxis::X);
		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Purple, "I'M RUNNING");
		AddMovementInput(tempFV, value);
		if (value > 0.0)
		{
			//Moving forward
			bIsPlayerGoingForward = true;
			bIsPlayerGoingBack = false;
		}
		if (value < 0.0)
		{
			//Moving backward
			bIsPlayerGoingForward = false;
			bIsPlayerGoingBack = true;
		}
	}
}

void AMainCharacter::MoveRight(float value)
{
	if ((Controller != NULL) && (value != 0.0f) && !bIsPushPulling && !bIsPraying)
	{
		
		if (!bIsWalking && !bIsIdle && !bIsSprinting)
		{
			SprintToIdleTimeline->Stop();
			RunToIdleTimeline->Stop();
			GetCharacterMovement()->MaxWalkSpeed = runSpeed;
		}
		// add movement in that direction
		AddMovementInput(RightVector, value);
		//leftOrRightPlayer = value;
		AddControllerYawInput(value*turnRate*deltaTime);
		//leftOrRightCamera = value*turnRate*deltaTime;

		if (value > 0.0)
		{
			//Moving right
			bIsPlayerGoingRight = true;
			bIsPlayerGoingLeft = false;
		}
		if (value < 0.0)
		{
			//Moving left
			bIsPlayerGoingRight = false;
			bIsPlayerGoingLeft = true;
		}
	}
	else
	{
		//leftOrRightCamera = 0.f;
		//leftOrRightPlayer = 0.f;
	}
	if (value == 0.0f)
	{
		bIsPlayerGoingRight = false;
		bIsPlayerGoingLeft = false;

	}
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, FString::Printf(TEXT("camera: %f"), leftOrRightCamera));
}

void AMainCharacter::Walk()
{
	bIsWalking = true;
	SprintToIdleTimeline->Stop();
	RunToIdleTimeline->Stop();
	GetCharacterMovement()->MaxWalkSpeed = walkSpeed;
}

void AMainCharacter::StopWalking()
{
	bIsWalking = false;
	GetCharacterMovement()->MaxWalkSpeed = runSpeed;
}

void AMainCharacter::Sprint()
{
	bIsSprinting = true;
	SprintToIdleTimeline->Stop();
	RunToIdleTimeline->Stop();
	GetCharacterMovement()->MaxWalkSpeed = sprintSpeed;
}

void AMainCharacter::StopSprinting()
{
	bIsSprinting = false;
	if (!bIsNoLocomotionInput)
	{
		GetCharacterMovement()->MaxWalkSpeed = runSpeed;
	}
	//GetCharacterMovement()->MaxWalkSpeed = runSpeed;
	//if (bIsNoLocomotionInput)
	//{
	//	SprintToIdleTimeline->PlayFromStart();
	//}
}

void AMainCharacter::TurnAround()
{
	bIsTurning = true;
}

void AMainCharacter::StopTurning()
{
	bIsTurning = false;
}

void AMainCharacter::TurnCamera(float value)
{
	AddControllerYawInput(value*turnRate*deltaTime);
}

void AMainCharacter::LookUp(float value)
{
	if (GetController())
	{
		AddControllerPitchInput(value*lookRate*deltaTime);
		FRotator clampedController = FRotator(FMath::ClampAngle(GetControlRotation().Pitch, -cameraDegreeCap, cameraDegreeCap), GetControlRotation().Yaw, GetControlRotation().Roll);
		GetController()->SetControlRotation(clampedController);
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, FString::Printf(TEXT("pitch: %f"), GetControlRotation().Pitch));
	}	
}

void AMainCharacter::Interact()
{
	bIsInteracting = true;
	//-------------------------------------------
	//PRAYING INTERACTION
	//-------------------------------------------
	TArray <AActor*> overlappingActors;
	overlappingSphere->GetOverlappingActors(overlappingActors);
	for (int32 overlappingActorIndex = 0; overlappingActorIndex < overlappingActors.Num(); overlappingActorIndex++)
	{
		AStatueObject* const overlappingTestSO = Cast<AStatueObject>(overlappingActors[overlappingActorIndex]);
		//if (overlappingTest) //This works
		if (overlappingTestSO && overlappingTestSO->bCanPlayerPray)
		{
			overlappingTestSO->bCanPlayerPray = false;

			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, overlappingTestSO->statueName);
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("YOU ARE PRAYING AT THE :")));
		
			bIsPraying = true;

		}
		else if (overlappingTestSO && !overlappingTestSO->bCanPlayerPray)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("YOU CAN'T PRAY AT ME ANYMORE")));
		}


		APickUpItem* const overlappingTestPUI = Cast<APickUpItem>(overlappingActors[overlappingActorIndex]);
		if (overlappingTestPUI && !overlappingTestPUI->IsPendingKill())
		{
			bIsPickingUp = true;
			Inventory.Add(overlappingTestPUI->itemType);
			overlappingTestPUI->Destroy();
			bIsPickingUp = false;
		}
		//-------------------------------------------
		//!PRAYING INTERACTION
		//-------------------------------------------
	}
	//Interact
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, FString::Printf(TEXT("BlockingHit: %i"), blockingHit));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, "I'M INTERACTING");
}
void AMainCharacter::StopInteract()
{
	bIsInteracting = false;
}

void AMainCharacter::OpenInventory()
{
	bIsInInventory = !bIsInInventory;
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, FString::Printf(TEXT("Inventory is: %i"), bIsInInventory));
}

void AMainCharacter::PushPull()
{
	
	
		//in a non-Static class
		//Draw the Line!
		FRotator tempRot = GetActorRotation();
		FRotator tempYaw = FRotator(0, tempRot.Yaw, 0);
		FVector tempFV = FRotationMatrix(tempYaw).GetUnitAxis(EAxis::X);
		FVector tempActorLocation = FVector(GetActorLocation().X, GetActorLocation().Y, GetActorLocation().Z + characterArmHeight);
		FVector end = (tempActorLocation + (tempFV * pushPullTraceCheckDistance));
		FHitResult results;
		FCollisionQueryParams query = FCollisionQueryParams(FName(TEXT("trace")), false, this);
		bool hit = GetWorld()->LineTraceSingleByChannel(results, tempActorLocation, end, ECC_Visibility, query);
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, FString::Printf(TEXT("BlockingHit: %i"), hit));
		attachedPushPullItem = Cast<APushPullItem>(results.GetActor());
		if (attachedPushPullItem)
		{
			GetCharacterMovement()->MaxWalkSpeed = pushPullSpeed;
		
			float distance = (GetActorLocation() - attachedPushPullItem->GetActorLocation()).Size();
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, FString::Printf(TEXT("ITS A PUSHPULL OBJECT")));

			FAttachmentTransformRules attachRules = FAttachmentTransformRules(EAttachmentRule::KeepWorld, false);
			attachedPushPullItem->AttachToActor(this, attachRules);
			MoveIgnoreActorAdd(attachedPushPullItem);
			GetCharacterMovement()->bOrientRotationToMovement = false;
			bIsPushPulling = !bIsPushPulling;
			//if (bIsPushPulling)
			//{
			//	storedLookRate = lookRate;
			//	storedturnRate = turnRate;
			//	lookRate = 0;
			//	turnRate = 0;
			//}
			//else
			//{
			//	lookRate = storedLookRate;
			//	turnRate = storedturnRate;
			//}
		}
	
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "I'M PUSHING/PULLING");
	//FVector temp = GetActorLocation() + GetActorForwardVector();
	//FVector end = FVector(GetActorForwardVector().X, GetActorForwardVector().Y + pushPullTraceCheckDistance, GetActorForwardVector().Z);

	if (!bIsPushPulling)
	{
		StopPushPull();
	}

}

void AMainCharacter::StopPushPull()
{
	
	if (attachedPushPullItem)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, FString::Printf(TEXT("ITS A PUSHPULL OBJECT")));
		FDetachmentTransformRules detachRules = FDetachmentTransformRules(EDetachmentRule::KeepWorld, false);
		attachedPushPullItem->DetachFromActor(detachRules);
		MoveIgnoreActorRemove(attachedPushPullItem);
	
		GetCharacterMovement()->MaxWalkSpeed = runSpeed;
		GetCharacterMovement()->bOrientRotationToMovement = true;
		bIsPushPulling = false;
		bPushPullColliding = false;

	}
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Silver, "I'M NOT PUSHING/PULLING");
}

void AMainCharacter::TimelineFloatReturn(float val)
{
	if (!bIsPushPulling)
	{
		FRotator tempRot = GetActorRotation();
		FRotator tempYaw = FRotator(0, tempRot.Yaw, 0);
		FVector tempFV = FRotationMatrix(tempYaw).GetUnitAxis(EAxis::X);
		AddMovementInput(tempFV, val);
	}	
}
