// MovingActor.cpp

#include "MovingActor.h"


AMovingActor::AMovingActor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComp"));
	StaticMeshComp->SetupAttachment(SceneRoot);


	MoveSpeed = 5.0f;
	MaxRange = 20.0f;
	StartLocation = GetActorLocation();

	PrimaryActorTick.bCanEverTick = true;

}


void AMovingActor::BeginPlay()
{
	Super::BeginPlay();
	
}



void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(MoveSpeed))
	{
		float DistanceMoved = FVector::Dist(StartLocation, GetActorLocation());

		if (DistanceMoved > MaxRange)
		{
			MoveSpeed *= -1;
		}
		else if (DistanceMoved < 1.0f && MoveSpeed < 0)
		{
			MoveSpeed *= -1;
		}

		FVector Offset = FVector(MoveSpeed * DeltaTime, 0.0f, 0.0f);

		AddActorLocalOffset(Offset);
	}

}