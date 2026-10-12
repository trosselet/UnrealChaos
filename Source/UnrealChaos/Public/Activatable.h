#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Activatable.generated.h"

class AActor;

UINTERFACE(MinimalAPI, Blueprintable)
class UActivatable: public UInterface
{
	GENERATED_BODY()
};
 
class UNREALCHAOS_API IActivatable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interfaces")
	void Activate(AActor* InInstigator);

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interfaces")
	void Deactivate(AActor* InInstigator);
};