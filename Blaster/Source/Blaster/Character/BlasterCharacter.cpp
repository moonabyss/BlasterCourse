// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ABlasterCharacter::ABlasterCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetMesh());
	CameraBoom->TargetArmLength = 600.f;
	CameraBoom->bUsePawnControlRotation = true;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	FollowCamera->bUsePawnControlRotation = false;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
}

void ABlasterCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABlasterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABlasterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);

	PlayerInputComponent->BindAxis("MoveForward", this, &ABlasterCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ABlasterCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ABlasterCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &ABlasterCharacter::LookUp);
}

//
// Basic Movement
//
void ABlasterCharacter::MoveForward(float Value)
{
	if (!Controller || Value == 0.f) return;

	const FRotator YawRotation{ 0.f, GetControlRotation().Yaw, 0.f };
	const FVector Direction{ FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X) };
	AddMovementInput(Direction, Value);
}

void ABlasterCharacter::MoveRight(float Value)
{
	if (!Controller || Value == 0.f) return;

	const FRotator YawRotation{ 0.f, GetControlRotation().Yaw, 0.f };
	const FVector Direction{ FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y) };
	AddMovementInput(Direction, Value);
}

void ABlasterCharacter::Turn(float Value)
{
	if (!Controller || Value == 0.f) return;

	AddControllerYawInput(Value);
}

void ABlasterCharacter::LookUp(float Value)
{
	if (!Controller || Value == 0.f) return;

	AddControllerPitchInput(Value);
}

