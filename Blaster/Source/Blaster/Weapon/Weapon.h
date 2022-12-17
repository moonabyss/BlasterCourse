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
class UWidgetComponent;

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
	UFUNCTION()
	void OnSphereOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
private:
	UPROPERTY(Category = "Weapon Properties", VisibleAnywhere)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(Category = "Weapon Properties", VisibleAnywhere)
	USphereComponent* AreaSphere;

	UPROPERTY(Category = "Weapon Properties", VisibleAnywhere)
 	EWeaponState WeaponState;

	UPROPERTY(Category = "Weapon Properties", VisibleAnywhere)
	UWidgetComponent* PickupWidget;
};
