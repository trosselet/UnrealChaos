#include "MecanismBase.h"
#include "EventSubsystem.h"

AMecanismBase::AMecanismBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AMecanismBase::Activate_Implementation(AActor* InInstigator)
{
	if (MechanismState == EMechanismState::Idle)
	{
		SetMechanismState(EMechanismState::Triggered, InInstigator);
	}
}

void AMecanismBase::Deactivate_Implementation(AActor* InInstigator)
{
	if (MechanismState == EMechanismState::Triggered)
	{
		SetMechanismState(EMechanismState::Idle, InInstigator);
	}
}

void AMecanismBase::SetMechanismState(EMechanismState NewState, AActor* InInstigator)
{
	if (MechanismState == NewState)
	{
		return;
	}

	MechanismState = NewState;
	OnStateEntered(NewState);
	OnStateChanged(NewState);

	FPhysicsEventData Event;
	Event.Type = EPhysicsEventType::MechanismStateChanged;
	Event.Source = this;
	Event.InstigatorActor = InInstigator;
	Event.Location = GetActorLocation();
	Event.Magnitude = static_cast<float>(NewState);
	UEventSubsystem::BroadcastPhysicsEvent(this, Event);
}