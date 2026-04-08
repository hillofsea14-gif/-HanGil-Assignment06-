// RotatingActor.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotatingActor.generated.h"

UCLASS()
class ASSIGNMENT06_API ARotatingActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotatingActor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="RotatingActor|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotatingActor|Components")
	UStaticMeshComponent* StaticMeshComp;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotatingActor|Materials")  아직은 스태틱 메시에 머터리얼 붙이는 법을 모름.
	//UMaterial* MaterialAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="RotatingActor|Properties")
	float RotationSpeed;


	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

};
