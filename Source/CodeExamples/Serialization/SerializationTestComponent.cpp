// Fill out your copyright notice in the Description page of Project Settings.

#include "SerializationTestComponent.h"

const FGuid USerializationTestComponent::VersionKey(0xB3C99A56, 0xA53A45BF, 0x93F27D09, 0xC7CA23E1);

const FName USerializationTestComponent::MyVersionName(TEXT("MySerializationVersion"));

FCustomVersionRegistration MySerializationRegistration(
	USerializationTestComponent::VersionKey,
	USerializationTestComponent::CustomVersion::V_Current,
	USerializationTestComponent::MyVersionName
);

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
	Ar.UsingCustomVersion(VersionKey);
	FString PathName = GetPathName();
	if (!IsTemplate() && Ar.CustomVer(VersionKey) < CustomVersion::V2)
	{
		volatile int i = 10;
    MyFloat = TNumericLimits<float>::Min();
	}
	Super::Serialize(Ar);
	if (!IsTemplate() && Ar.CustomVer(VersionKey) < CustomVersion::V2) 
	{
		if (MyFloat!= TNumericLimits<float>::Min())
		{
   			MyFloat *= 3;
		}
		else
		{
			MyFloat = GetDefault<USerializationTestComponent>()->MyFloat;
		}
		// I found serialization only copies the default values
		// When default is not default, it is zeroed. out
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

