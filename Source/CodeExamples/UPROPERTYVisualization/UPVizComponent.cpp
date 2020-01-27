// Fill out your copyright notice in the Description page of Project Settings.


#include "UPVizComponent.h"

// Sets default values for this component's properties
UUPVizComponent::UUPVizComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUPVizComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UUPVizComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UUPVizComponent::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	FName ChangedPropertyName = PropertyChangedEvent.Property->GetFName();
	if (ChangedPropertyName == GET_MEMBER_NAME_CHECKED(UUPVizComponent, TestEditInt))
	{
		UpdateVisualization();
	}
	else if (ChangedPropertyName == GET_MEMBER_NAME_CHECKED(UUPVizComponent, TestEditArray))
	{
		UpdateVisualization();
	}
	else if (ChangedPropertyName == GET_MEMBER_NAME_CHECKED(UUPVizComponent, TestEditMap))
	{
		UpdateVisualization();
	}
	else if (ChangedPropertyName == GET_MEMBER_NAME_CHECKED(UUPVizComponent, TestEditSet))
	{
		UpdateVisualization();
	}
	else
	{
	}

	Super::PostEditChangeProperty(PropertyChangedEvent);
}

void UUPVizComponent::PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent)
{
  FName ChangedPropertyName = PropertyChangedEvent.Property->GetFName();
	
  auto Head = PropertyChangedEvent.PropertyChain.GetHead();
	auto Tail = PropertyChangedEvent.PropertyChain.GetTail();

	for (auto Node : PropertyChangedEvent.PropertyChain)
	{
		Node;
	}

	if (ChangedPropertyName == GET_MEMBER_NAME_CHECKED(UUPVizComponent, TestEditArray))
  {

  }
  else if (ChangedPropertyName == GET_MEMBER_NAME_CHECKED(UUPVizComponent, TestEditMap))
  {
  }
  else if (ChangedPropertyName == GET_MEMBER_NAME_CHECKED(UUPVizComponent, TestEditSet))
  {
  }
  else
  {
  }

	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}

void UUPVizComponent::UpdateVisualization()
{
	UpdatedInteger = TestEditInt;
	UpdatedArray = TestEditArray;
	UpdatedSet = TestEditSet;
}

