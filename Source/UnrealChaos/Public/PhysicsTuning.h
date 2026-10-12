#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PhysicsTuning.generated.h"
 
UCLASS(BlueprintType)
class UNREALCHAOS_API UPhysicsTuning : public UPrimaryDataAsset
{
	GENERATED_BODY()

public: 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Propulsion", meta = (ClampMin = "0"))
	float JumpPadImpulse = 1200.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Propulsion", meta = (ClampMin = "0"))
	float ExplosionRadius = 600.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Propulsion", meta = (ClampMin = "0"))
	float ExplosionImpulse = 2500.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Propulsion", meta = (ClampMin = "0"))
	float WindForce = 800.f;
	 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grab", meta = (ClampMin = "0"))
	float GrabDistance = 250.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grab", meta = (ClampMin = "0"))
	float MaxGrabMass = 60.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Grab", meta = (ClampMin = "0"))
	float ThrowImpulse = 1500.f;
	 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Destruction", meta = (ClampMin = "0"))
	float MinImpulseToBreak = 800.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Destruction", meta = (ClampMin = "0"))
	float ChaosStrainMultiplier = 1.f;
	 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Feedback", meta = (ClampMin = "1"))
	float ReferenceMaxImpulse = 3000.f;
	 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Feedback")
	FVector2D FeedbackScaleRange = FVector2D(0.5, 2.0);

	UFUNCTION(BlueprintPure, Category = "Feedback")
	float NormalizeImpulse(float Impulse) const;

	UFUNCTION(BlueprintPure, Category = "Feedback")
	float GetFeedbackScale(float Impulse) const;
};