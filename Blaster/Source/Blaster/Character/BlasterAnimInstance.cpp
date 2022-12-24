// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterAnimInstance.h"
#include "GameFramework/CharacterMovementComponent.h"

#include "BlasterCharacter.h"

void UBlasterAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	BlasterCharacter = Cast<ABlasterCharacter>(TryGetPawnOwner());
}

void UBlasterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!BlasterCharacter)
	{
		BlasterCharacter = Cast<ABlasterCharacter>(TryGetPawnOwner());
	}

	if (!BlasterCharacter) return;

	FVector Velocity = BlasterCharacter->GetVelocity();
	Velocity.Z = 0.f;
	Speed = Velocity.Size();

	UCharacterMovementComponent* Movement = BlasterCharacter->GetCharacterMovement();

	bIsInAir = Movement->IsFalling();
	bIsAccelerating = Movement->GetCurrentAcceleration().Size() > 0.f ? true : false;
	bWeaponEquipped = BlasterCharacter->IsWeaponEquipped();
	bIsCrouched = BlasterCharacter->bIsCrouched;
}
