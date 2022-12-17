// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)
enum class EWeaponState : uint8
{
	EWS_Initial UMETA(DisplayName = "Initial State"),
	EWS_Equiupped UMETA(DisplayName = "Equiupped"),
	EWS_Dropped UMETA(DisplayName = "Dropped"),

	EWS_MAX UMETA(DisplayName = "DefaultMAX")
};

class USphereComponent;

UCLASS()
class BLASTER_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	AWeapon();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:	

protected:
	
private:
	UPROPERTY(Category = "Weapon Properties", VisibleAnywhere)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(Category = "Weapon Properties", VisibleAnywhere)
	USphereComponent* AreaSphere;

 	EWeaponState WeaponState;
};
