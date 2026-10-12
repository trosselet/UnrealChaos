// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ChaosTypes.h"
#include "EventSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPhysicsEvent, const FPhysicsEventData&, Event);
 
UCLASS()
class UNREALCHAOS_API UEventSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintAssignable, Category = "Events")
	FOnPhysicsEvent OnPhysicsEvent;

	UFUNCTION(BlueprintCallable, Category = "Events")
	void Broadcast(const FPhysicsEventData& Event);

	UFUNCTION(BlueprintCallable, Category = "Events", meta = (WorldContext = "WorldContextObject"))
	static void BroadcastPhysicsEvent(const UObject* WorldContextObject, const FPhysicsEventData& Event);

	static UEventSubsystem* Get(const UObject* WorldContextObject);
};