// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyInterface.h"
#include "GCTestActor.generated.h"

UCLASS()
class CODEEXAMPLES_API UGCTester : public UObject, public IMyInterface
{
	GENERATED_BODY()

public:
	UGCTester() {
		UE_LOG(LogTemp, Log, TEXT("%s Constructucted"), *GetName());
	}

	UPROPERTY()
		int A;

	void Foo(const FString& S) const override { UE_LOG(LogTemp, Log, TEXT("%s"), *S); }
};

UCLASS()
class CODEEXAMPLES_API AGCTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGCTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void CreateTestObjects();

	void PrintTestObjects() const;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Test if items stored here are actually garbage collected
	
	// No longer valid after GC
	TArray<UObject*> NonUPObjArray;
	// No longer valid after GC
	TArray<IMyInterface*> NonUPInterfaceArray;

	// Still vaild after GC
	UPROPERTY(VisibleAnywhere)
	TArray<UObject*> UPObjArray;

	// Still valid after GC
	UPROPERTY(VisibleAnywhere)
	TArray<TScriptInterface<IMyInterface>> UPInterfaceArray;

};
