// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SerializationTestComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODEEXAMPLES_API USerializationTestComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USerializationTestComponent();

	void Serialize(FArchive& Ar) override;
protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	float MyFloat = 100.f;

  UPROPERTY(EditAnywhere)
  double MyDouble = 10.0;

	static const FGuid VersionKey;

	static const FName MyVersionName;

	enum CustomVersion{
		V1 = 1,
		V2 = 2,
		V_Current = V2
	};

	const CustomVersion MyVersion = CustomVersion::V2;
};
