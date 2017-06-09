// Fill out your copyright notice in the Description page of Project Settings.

#include "Ava.h"
#include "MainCharacter.h"


// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	walkSpeed = 50;
	runSpeed = 150;
	sprintSpeed = 350;
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
	FollowCamera->bUsePawnControlRotation = true; // Camera does not rotate relative to arm

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);
	InputComponent->BindAction("Jump", IE_Pressed, this, &AMainCharacter::Jump);
	InputComponent->BindAction("Jump", IE_Released, this, &AMainCharacter::StopJumping);
	//Bind our axis inputs for movement.
	InputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AMainCharacter::MoveRight);

	InputComponent->BindAction("Run", IE_Pressed, this, &AMainCharacter::Sprint);
	InputComponent->BindAction("Run", IE_Released, this, &AMainCharacter::StopSprinting);

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
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation = FRotator(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, value);
	}
}

void AMainCharacter::MoveRight(float value)
{

	if ((Controller != NULL) && (value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, value, 0);
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, value);
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
	FRotator CameraRotation = FRotator(0, value, 0);
	Controller->AddActorLocalRotation(CameraRotation, false);
}

void AMainCharacter::LookUp(float value)
{
	FRotator CameraRotation = FRotator(value,0,0);
	Controller->AddActorLocalRotation(CameraRotation, false);
}
