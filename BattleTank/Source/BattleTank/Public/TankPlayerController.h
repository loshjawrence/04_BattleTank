// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h" //generated.h must be the last include

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* GetControlledTank() const;
	
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	//Start the tank moving the barrel so that a shot would hit where 
	//the crosshair intersects the world
	void AimTowardsCrosshair();


	//returns an out param, true if hit land
	bool GetSightRayHitLocation(FVector& OUT HitLocation) const;


	//Get world loc if raytrace through crosshair, true if hits land


	bool GetLookVectorHitLocation(const FVector & LookDirection, FVector & HitLocation) const;

	bool GetLookDirection(const FVector2D & ScreenLocation, FVector & LookDirection) const;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5;

	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.3333;

	UPROPERTY(EditAnywhere)
    float LineTraceRange = 1000000;
};
