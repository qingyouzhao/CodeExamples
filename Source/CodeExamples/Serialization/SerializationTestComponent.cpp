// Fill out your copyright notice in the Description page of Project Settings.


#include "SerializationTestComponent.h"

// Sets default values for this component's properties
USerializationTestComponent::USerializationTestComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void USerializationTestComponent::Serialize(FArchive& Ar)
{
	if (!IsTemplate())
	{
		volatile int i = 10;
	}
	Super::Serialize(Ar);
  if (!IsTemplate())
  {
    volatile int i = 10;
  }
}

// Called when the game starts
void USerializationTestComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USerializationTestComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

