// Fill out your copyright notice in the Description page of Project Settings.


#include "Weapon/Gun.h"

#include "NiagaraComponent.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");

	SetRootComponent(WeaponSkeletalMesh);

	FireEffect = CreateDefaultSubobject<UNiagaraComponent>("FireEffect");
	FireEffect->SetupAttachment(RootComponent);
}

int AGun::GetWeaponSize()
{
	return 0;
}

void AGun::DestroyWeapon()
{
}

