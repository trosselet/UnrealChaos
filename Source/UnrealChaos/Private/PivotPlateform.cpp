#include "PivotPlateform.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/CollisionProfile.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"

APivotPlateform::APivotPlateform()
{
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Platform = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	Platform->SetupAttachment(Root);
	Platform->SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	Platform->SetSimulatePhysics(true);

	Constraint = CreateDefaultSubobject<UPhysicsConstraintComponent>(TEXT("Constraint"));
	Constraint->SetupAttachment(Root); 
	Constraint->ComponentName2.ComponentName = TEXT("Platform");
}

void APivotPlateform::BeginPlay()
{
	Super::BeginPlay();
	LockPlatform();
}

void APivotPlateform::LockPlatform()
{
	Constraint->SetLinearXLimit(LCM_Locked, 0.f);
	Constraint->SetLinearYLimit(LCM_Locked, 0.f);
	Constraint->SetLinearZLimit(LCM_Locked, 0.f);
	Constraint->SetAngularSwing1Limit(ACM_Locked, 0.f);
	Constraint->SetAngularSwing2Limit(ACM_Locked, 0.f);
	Constraint->SetAngularTwistLimit(ACM_Locked, 0.f);
}

void APivotPlateform::ReleasePlatform()
{ 
	Constraint->SetAngularTwistLimit(ACM_Limited, TipAngle);

	const FVector HingeAxis = Constraint->GetComponentRotation().RotateVector(FVector::XAxisVector);
	Platform->AddAngularImpulseInDegrees(HingeAxis * KickSpeed, NAME_None, true);
}

void APivotPlateform::OnStateEntered(EMechanismState NewState)
{
	if (NewState == EMechanismState::Triggered)
	{
		ReleasePlatform();
	}
	else if (NewState == EMechanismState::Idle)
	{
		LockPlatform();
	}
}