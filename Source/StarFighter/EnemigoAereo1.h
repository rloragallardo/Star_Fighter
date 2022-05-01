// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "NaveAerea.h"
#include "EnemigoAereo1.generated.h"

/**
 * 
 */
UCLASS()
class STARFIGHTER_API AEnemigoAereo1 : public ANaveAerea
{
	GENERATED_BODY()
		void Tick(float DeltaSeconds);
public:
	float MovementX;
	float MovementY;
};
