#pragma once

#include "CoreMinimal.h"
#include "MecanismBase.h"
#include "PressurePlate.generated.h"

class UBoxComponent;
class UStaticMeshComponent;

UCLASS()
class UNREALCHAOS_API APressurePlate : public AMecanismBase
{
	GENERATED_BODY()

public:
	APressurePlate();
	 
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly, Category = "Plate")
	TArray<TObjectPtr<AActor>> Targets;
	 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Plate", meta = (ClampMin = "0"))
	float RequiredMass = 0.f;

protected:
	virtual void BeginPlay() override;
	virtual void OnStateEntered(EMechanismState NewState) override;

	UFUNCTION()
	void OnTriggerBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnTriggerEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plate")
	TObjectPtr<UStaticMeshComponent> PlateMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Plate")
	TObjectPtr<UBoxComponent> Trigger;

private:
	void Refresh(AActor* InInstigator);

	TSet<TWeakObjectPtr<UPrimitiveComponent>> Overlapping;
};