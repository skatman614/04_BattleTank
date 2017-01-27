// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void RotateTurret(float RelativeSpeed);
	
private:

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxRotationPerSecond = 25.f;
	
	
	
	
};
