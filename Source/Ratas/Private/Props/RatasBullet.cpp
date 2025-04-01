// Fill out your copyright notice in the Description page of Project Settings.


#include "Props/RatasBullet.h"

// Sets default values
ARatasBullet::ARatasBullet(const int _Damage, const float _Speed, const float _ReloadTimer, const FVector& _Location, const FRotator& _Rotation): Damage(_Damage), Speed(_Speed), DespawnTimer(_ReloadTimer)
{
	SetActorRotation(_Rotation);
	SetActorLocation(_Location);
}