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
	bIsInInventory = false;
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.f);

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
	CameraBoom->TargetArmLength = 400.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	//** DEPRECATED NEEDS CHANGING : AttachToComponent**
	FollowCamera->AttachTo(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm


	prayingSphere = CreateDefaultSubobject<USphereComponent>(TEXT("prayingSphere"));
	prayingSphere->SetSphereRadius(100.f);
	prayingSphere->AttachTo(RootComponent);

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	deltaTime = DeltaTime;

	//For Controller:
	float speed = GetVelocity().Size();
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
	else
	{
		bIsWalking = false;
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
	InputComponent->BindAction("PushPull", IE_Released, this, &AMainCharacter::StopPushPull);

	//Bind open/Close Inventory Functionalities to input mapping "PushPull"
	InputComponent->BindAction("Inventory", IE_Pressed, this, &AMainCharacter::OpenInventory);

	//Bind open/Close Inventory Functionalities to input mapping "PushPull"
	InputComponent->BindAction("Interact", IE_Pressed, this, &AMainCharacter::Interact);

	//Bind our axis inputs for movement.
	InputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);

	InputComponent->BindAxis("Turn", this, &AMainCharacter::TurnCamera);
	InputComponent->BindAxis("LookUp", this, &AMainCharacter::LookUp);




	InputComponent->BindAction("TurnAround", IE_Pressed, this, &AMainCharacter::TurnAround);
}

void AMainCharacter::Jump()
{
	Super::Jump();
	bIsJumping = true;
}

void AMainCharacter::StopJumping()
{
	Super::StopJumping();
	bIsJumping = false;
}

void AMainCharacter::MoveForward(float value)
{
	if ((Controller != NULL) && (value != 0.0f))
	{
		//GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Purple, "I'M RUNNING");
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation = FRotator(0, Rotation.Yaw, 0);
		const FVector ForwardVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(ForwardVector, value);
	}
}

void AMainCharacter::MoveRight(float value)
{

	if ((Controller != NULL) && (value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation = FRotator(0, Rotation.Yaw, 0);
		// get right vector 
		const FVector RightVector = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(RightVector, value);

	}
}

void AMainCharacter::Walk()
{
	bIsWalking = true;
	GetCharacterMovement()->MaxWalkSpeed = walkSpeed;
}

void AMainCharacter::StopWalking()
{
	bIsWalking = false;
	GetCharacterMovement()->MaxWalkSpeed = runSpeed;
}

void AMainCharacter::Sprint()
{
	GEngine->AddOnScreenDebugMessage(-1, 0.1f, FColor::Purple, "I'M SPRINTING");
	bIsSprinting = true;
	GetCharacterMovement()->MaxWalkSpeed = sprintSpeed;
}

void AMainCharacter::StopSprinting()
{
	bIsSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = runSpeed;
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
	AddControllerPitchInput(value*lookRate*deltaTime);
}

void AMainCharacter::Interact()
{
	TArray <AActor*> overlappingActors;
	prayingSphere->GetOverlappingActors(overlappingActors);
	for (int32 overlappingActorIndex = 0; overlappingActorIndex < overlappingActors.Num(); overlappingActorIndex++)
	{
		AStatueObject* const overlappingTest = Cast<AStatueObject>(overlappingActors[overlappingActorIndex]);
		//if (overlappingTest) //This works
		if (overlappingTest && overlappingTest->bCanPlayerPray)
		{
			overlappingTest->bCanPlayerPray = false;

			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, overlappingTest->StatueName);
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("YOU ARE PRAYING AT THE :")));

		}
		else if (overlappingTest && !overlappingTest->bCanPlayerPray)
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, FString::Printf(TEXT("YOU CAN'T PRAY AT ME ANYMORE")));
		}
	}
	//Interact
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, FString::Printf(TEXT("BlockingHit: %i"), blockingHit));
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, "I'M INTERACTING");
}

void AMainCharacter::OpenInventory()
{
	bIsInInventory = !bIsInInventory;
	GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Emerald, FString::Printf(TEXT("Inventory is: %i"), bIsInInventory));
}

void AMainCharacter::PushPull()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "I'M PUSHING/PULLING");
}

void AMainCharacter::StopPushPull()
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Silver, "I'M NOT PUSHING/PULLING");
}
