// Fill out your copyright notice in the Description page of Project Settings.


#include "Bala.h"
#include "UObject/ConstructorHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Engine/StaticMesh.h"

ABala::ABala()
{	
	
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BalaMeshAsset(TEXT("StaticMesh'/Game/TwinStick/Meshes/TwinStickProjectile.TwinStickProjectile'"));
	PrimaryActorTick.bCanEverTick = true;
	BalaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BalaMesh0"));
	BalaMesh->SetStaticMesh(BalaMeshAsset.Object);
	BalaMesh->SetupAttachment(RootComponent);
	BalaMesh->BodyInstance.SetCollisionProfileName("Bala");
	BalaMesh->OnComponentHit.AddDynamic(this, &AProyectil::OnHit);		// set up a notification for when this component hits something
	RootComponent = BalaMesh;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	BalaMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("BalaMovement0"));
	BalaMovement->UpdatedComponent = BalaMesh;
	BalaMovement->InitialSpeed = 3000.f;
	BalaMovement->MaxSpeed = 3000.f;
	BalaMovement->bRotationFollowsVelocity = true;
	BalaMovement->bShouldBounce = false;
	BalaMovement->ProjectileGravityScale = 0.f; // No gravity

	// Die after 3 seconds by default
	InitialLifeSpan = 3.0f;

}
