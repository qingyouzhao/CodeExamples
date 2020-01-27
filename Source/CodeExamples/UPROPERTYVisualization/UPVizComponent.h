// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UPVizComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CODEEXAMPLES_API UUPVizComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUPVizComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

#if WITH_EDITOR

	/**
	 * Called when a property on this object has been modified externally
	 *
	 * @param PropertyThatChanged the property that was modified
	 */
	void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	/**
	 * This alternate version of PostEditChange is called when properties inside structs are modified.  The property that was actually modified
	 * is located at the tail of the list.  The head of the list of the UStructProperty member variable that contains the property that was modified.
	 */
	void PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent) override;

	void UpdateVisualization();

  UPROPERTY(EditAnywhere, Category = Test)
  int TestEditInt;

	UPROPERTY(EditAnywhere, Category = Test)
	TArray<int> TestEditArray;
  
	UPROPERTY(EditAnywhere, Category = Test)
  TMap<int, FString> TestEditMap;
  
	UPROPERTY(EditAnywhere, Category = Test)
  TSet<int> TestEditSet;

	UPROPERTY(VisibleAnywhere, Category = "Test | Visualization")
	int UpdatedInteger;

  UPROPERTY(VisibleAnywhere, Category = "Test | Visualization")
  TArray<int> UpdatedArray;

  UPROPERTY(VisibleAnywhere, Category = "Test | Visualization")
  TSet<int> UpdatedSet;

#endif
};
