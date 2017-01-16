// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" // Must be the last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:


private:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;

	virtual void Tick( float DeltaTime ) override;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(OUT FVector& HitLocation) const;

	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.333f;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;


};
