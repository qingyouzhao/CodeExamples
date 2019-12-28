// Fill out your copyright notice in the Description page of Project Settings.


#include "GCTestActor.h"

// Sets default values
AGCTestActor::AGCTestActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGCTestActor::BeginPlay()
{
	Super::BeginPlay();
	CreateTestObjects();
	
}

void AGCTestActor::CreateTestObjects()
{
	NonUPObjArray.Add(NewObject<UGCTester>());
	NonUPInterfaceArray.Add(NewObject<UGCTester>());
	UPObjArray.Add(NewObject<UGCTester>());
	UPInterfaceArray.Add(NewObject<UGCTester>());
}

void AGCTestActor::PrintTestObjects() const
{
	for (const UObject* O : NonUPObjArray)
	{
		if (O->IsValidLowLevel())
		{
			UE_LOG(LogTemp, Log, TEXT("Non UPROPERTY Array object is still valid"));
		}
		else
		{
			// After GC, this is expected to be called
      UE_LOG(LogTemp, Warning, TEXT("Non UPROPERTY Array object is NO LONGER valid"));
		}
	}

	for (const UObject* O : UPObjArray)
  {
    if (O->IsValidLowLevel())
    {
			// This is expected to be called all the time
      UE_LOG(LogTemp, Log, TEXT("UPROPERTY Array object is still valid"));
    }
    else
    {
      UE_LOG(LogTemp, Warning, TEXT("UPROPERTY Array object is NO LONGER valid"));
    }
  }

  for (const TScriptInterface<IMyInterface>& I : UPInterfaceArray)
  {
    if (I)
    {
			// I is expected to be always valid unless we do full purge
      I->Foo(TEXT("Foo UPInterfaceArray"));
    }
  }

	return;
	// The following part is not a good thing to call 
	for (const IMyInterface* I : NonUPInterfaceArray)
	{
		if (I)
		{
			I->Foo(TEXT("Foo NonUPInterfaceArray"));
		}
	}
}

// Called every frame
void AGCTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	PrintTestObjects();
	if (GFrameCounter % 20 == 0 || GFrameNumber % 20 == 0)
	{
		GEngine->ForceGarbageCollection(true);
    UE_LOG(LogTemp, Log, TEXT("GC Full purge"));
	}
}

