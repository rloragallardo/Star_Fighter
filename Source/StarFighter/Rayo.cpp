// Fill out your copyright notice in the Description page of Project Settings.


#include "Rayo.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"

ARayo::ARayo()
{

	static ConstructorHelpers::FObjectFinder<UStaticMesh> RayoMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickBala.TwinStickBala'"));
	PrimaryActorTick.bCanEverTick = true;
	RayoMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RayoMesh0"));
	RayoMesh->SetStaticMesh(RayoMeshAsset.Object);
	RayoMesh->SetupAttachment(RootComponent);
	RayoMesh->BodyInstance.SetCollisionProfileName("Rayo");
	RayoMesh->OnComponentHit.AddDynamic(this, &AProyectil::OnHit);		// set up a notification for when this component hits something
	RootComponent = RayoMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	RayoMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("RayoMovement0"));
	RayoMovement->UpdatedComponent = RayoMesh;
	RayoMovement->InitialSpeed = 6000.f;
	RayoMovement->MaxSpeed = 6000.f;
	RayoMovement->bRotationFollowsVelocity = true;
	RayoMovement->bShouldBounce = false;
	RayoMovement->ProjectileGravityScale = 0.f; // No gravity

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

}
