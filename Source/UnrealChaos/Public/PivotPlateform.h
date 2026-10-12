#pragma once

#include "CoreMinimal.h"
#include "MecanismBase.h"
#include "PivotPlateform.generated.h"

class UStaticMeshComponent;
class UPhysicsConstraintComponent;

UCLASS()
class UNREALCHAOS_API APivotPlateform : public AMecanismBase
{
	GENERATED_BODY()

public:
	APivotPlateform();
	 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pivot", meta = (ClampMin = "0", ClampMax = "90"))
	float TipAngle = 40.f;
	 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Pivot")
	float KickSpeed = 60.f;

protected:
	virtual void BeginPlay() override;
	virtual void OnStateEntered(EMechanismState NewState) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pivot")
	TObjectPtr<USceneComponent> Root;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pivot")
	TObjectPtr<UStaticMeshComponent> Platform;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pivot")
	TObjectPtr<UPhysicsConstraintComponent> Constraint;

private:
	void LockPlatform();
	void ReleasePlatform();
};