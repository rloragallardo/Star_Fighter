// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemigoAereo2.h"
#include "time.h"


void AEnemigoAereo2::Tick(float DeltaSeconds)
{
	srand(time(NULL));

	//MovementX = rand() % 12 - 5;
	MovementY = rand() % 12 - 5;

	MoveSpeed = 40;


	const FVector MoveDirection = FVector(0.0f, MovementY, 0.0f);
	const FVector Movement = MoveDirection * MoveSpeed * DeltaSeconds;

	if (Movement.SizeSquared() > 0.0f)
	{
		const FRotator NewRotation = Movement.Rotation();

		FHitResult Hit(1.0f);
		RootComponent->MoveComponent(Movement, NewRotation, true, &Hit);
	}
}
