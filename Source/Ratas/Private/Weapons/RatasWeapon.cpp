// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapons/RatasWeapon.h"

// Sets default values
ARatasWeapon::ARatasWeapon()
{

	Damage = 0;
	Delay = 0;
	
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARatasWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARatasWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ARatasWeapon::Trigger()
{
}

