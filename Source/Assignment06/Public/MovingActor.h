// MovingActor.h
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class ASSIGNMENT06_API AMovingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMovingActor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="MovingActor|Components");
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="MovingActor|Components");
	UStaticMeshComponent* StaticMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor|Properties");
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MovingActor|Properties");
	float MaxRange;

	FVector StartLocation;

	virtual void BeginPlay() override;



public:	
	virtual void Tick(float DeltaTime) override;
	

};
