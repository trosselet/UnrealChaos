#include "PressurePlate.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

APressurePlate::APressurePlate()
{
	PlateMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlateMesh"));
	SetRootComponent(PlateMesh);

	Trigger = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger"));
	Trigger->SetupAttachment(PlateMesh);
	Trigger->SetBoxExtent(FVector(60.f, 60.f, 30.f));
	Trigger->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	Trigger->SetCollisionObjectType(ECC_WorldDynamic);
	Trigger->SetCollisionResponseToAllChannels(ECR_Ignore);
	Trigger->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	Trigger->SetCollisionResponseToChannel(ECC_PhysicsBody, ECR_Overlap);
}

void APressurePlate::BeginPlay()
{
	Super::BeginPlay();
	Trigger->OnComponentBeginOverlap.AddDynamic(this, &APressurePlate::OnTriggerBegin);
	Trigger->OnComponentEndOverlap.AddDynamic(this, &APressurePlate::OnTriggerEnd);
}

void APressurePlate::OnTriggerBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherComp)
	{
		Overlapping.Add(OtherComp);
		Refresh(OtherActor);
	}
}

void APressurePlate::OnTriggerEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherComp)
	{
		Overlapping.Remove(OtherComp);
		Refresh(OtherActor);
	}
}

void APressurePlate::Refresh(AActor* InInstigator)
{
	float TotalMass = 0.f;
	for (auto It = Overlapping.CreateIterator(); It; ++It)
	{
		if (const UPrimitiveComponent* Comp = It->Get())
		{
			TotalMass += Comp->GetMass();
		}
		else
		{
			It.RemoveCurrent();
		}
	}

	const bool bShouldBeOn = Overlapping.Num() > 0 && TotalMass >= RequiredMass;
	if (bShouldBeOn)
	{
		IActivatable::Execute_Activate(this, InInstigator);
	}
	else
	{
		IActivatable::Execute_Deactivate(this, InInstigator);
	}
}

void APressurePlate::OnStateEntered(EMechanismState NewState)
{
	for (AActor* Target : Targets)
	{
		if (!Target || !Target->Implements<UActivatable>())
		{
			continue;
		}

		if (NewState == EMechanismState::Triggered)
		{
			IActivatable::Execute_Activate(Target, this);
		}
		else if (NewState == EMechanismState::Idle)
		{
			IActivatable::Execute_Deactivate(Target, this);
		}
	}
}