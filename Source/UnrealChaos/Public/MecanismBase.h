#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChaosTypes.h"
#include "Activatable.h"
#include "MecanismBase.generated.h"

class UPhysicsTuning;
 
UCLASS(Abstract)
class UNREALCHAOS_API AMecanismBase : public AActor, public IActivatable
{
	GENERATED_BODY()

public:
	AMecanismBase();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Mechanism")
	TObjectPtr<UPhysicsTuning> Tuning;

	UFUNCTION(BlueprintPure, Category = "Mechanism")
	EMechanismState GetMechanismState() const { return MechanismState; }

	virtual void Activate_Implementation(AActor* InInstigator) override;
	virtual void Deactivate_Implementation(AActor* InInstigator) override;

protected: 
	UFUNCTION(BlueprintImplementableEvent, Category = "Mecanism")
	void OnStateChanged(EMechanismState NewState);
	 
	virtual void OnStateEntered(EMechanismState NewState) {}

	void SetMechanismState(EMechanismState NewState, AActor* InInstigator);

	UPROPERTY(BlueprintReadOnly, Category = "Mecanism")
	EMechanismState MechanismState = EMechanismState::Idle;
};