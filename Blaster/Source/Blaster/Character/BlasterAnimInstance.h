// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BlasterAnimInstance.generated.h"

class ABlasterCharacter;

/**
 * 
 */
UCLASS()
class BLASTER_API UBlasterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

private:
	UPROPERTY(Category = "Character", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	ABlasterCharacter* BlasterCharacter;

	UPROPERTY(Category = "Movement", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	float Speed;

	UPROPERTY(Category = "Movement", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bIsInAir;

	UPROPERTY(Category = "Movement", BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	bool bIsAccelerating;
};
