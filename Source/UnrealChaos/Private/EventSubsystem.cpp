
#include "EventSubsystem.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

void UEventSubsystem::Broadcast(const FPhysicsEventData& Event)
{
	OnPhysicsEvent.Broadcast(Event);
}

void UEventSubsystem::BroadcastPhysicsEvent(const UObject* WorldContextObject, const FPhysicsEventData& Event)
{
	if (UEventSubsystem* Bus = Get(WorldContextObject))
	{
		Bus->Broadcast(Event);
	}
}

UEventSubsystem* UEventSubsystem::Get(const UObject* WorldContextObject)
{
	const UWorld* World = GEngine ? GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull) : nullptr;
	return World ? World->GetSubsystem<UEventSubsystem>() : nullptr;
}