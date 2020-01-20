// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SwapClass/MyMeshComponent.h"
#include "ProceduralMeshComponent.h"
#include "MyNextMeshComponent.generated.h"

/**
 * 
 */
UCLASS(editinlinenew, meta = (BlueprintSpawnableComponent))
class CODEEXAMPLES_API UMyNextMeshComponent : public UProceduralMeshComponent
{
	GENERATED_BODY()
public:
  UMyNextMeshComponent();
};
