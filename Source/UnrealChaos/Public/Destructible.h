#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Destructible.generated.h"

class AActor;

UINTERFACE(MinimalAPI, Blueprintable)
class UDestructible : public UInterface
{
	GENERATED_BODY()
};
 
class UNREALCHAOS_API IDestructible
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interfaces")
	void ApplyDestructiveImpulse(FVector Location, float Radius, float Strength, AActor* InInstigator);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interfaces")
	bool IsDestroyed() const;
};