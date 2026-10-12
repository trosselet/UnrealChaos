#include "PhysicsTuning.h"

float UPhysicsTuning::NormalizeImpulse(float Impulse) const
{
	return FMath::Clamp(Impulse / FMath::Max(ReferenceMaxImpulse, KINDA_SMALL_NUMBER), 0.f, 1.f);
}

float UPhysicsTuning::GetFeedbackScale(float Impulse) const
{
	return FMath::Lerp(FeedbackScaleRange.X, FeedbackScaleRange.Y, NormalizeImpulse(Impulse));
}