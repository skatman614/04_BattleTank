// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTrack;
class UTankAimingComponent;
class AProjectile;
class UTankTurret;
class UTankMovementComponent;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTankLeftTrackReference(UTankTrack * TrackToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTankRightTrackReference(UTankTrack * TrackToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void Fire();

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

	AProjectile* ProjectileComponent = nullptr;

	UPROPERTY(BlueprintReadOnly, Category = Testing)
	UTankMovementComponent* TankMovementComponent = nullptr;


private:
	// Sets default values for this pawn's properties
	ATank();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float LaunchSpeed = 4000.f;

	UPROPERTY(EditDefaultsOnly, Category = Firing)
	float ReloadTimeInSeconds = 3.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	// Local barrel reference for spawn
	UTankBarrel* Barrel = nullptr;

	UTankTrack* TankLeftTrack = nullptr;

	UTankTrack* TankRightTrack = nullptr;

	double LastFireTime = 0;
		
};
