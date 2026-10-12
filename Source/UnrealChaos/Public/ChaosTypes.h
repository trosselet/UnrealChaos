// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h" 
#include "ChaosTypes.generated.h"

class AActor;

UENUM(BlueprintType)
enum class EMechanismState : uint8
{
	Idle,
	Triggered,
	Resolved
};

UENUM(BlueprintType)
enum class EPlayerMovementState : uint8
{
	Grounded,
	Airborne,
	Carrying
};

UENUM(BlueprintType)
enum class EPhysicsEventType : uint8
{
	MechanismStateChanged,
	ObjectDestroyed,
	Impact,
	Launched,
	Grabbed,
	Thrown,
	Explosion
};

USTRUCT(BlueprintType)
struct FPhysicsEventData
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	EPhysicsEventType Type = EPhysicsEventType::Impact;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	TObjectPtr<AActor> Source = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	TObjectPtr<AActor> InstigatorActor = nullptr;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	FVector Location = FVector::ZeroVector;
	 
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Events")
	float Magnitude = 0.f;
};