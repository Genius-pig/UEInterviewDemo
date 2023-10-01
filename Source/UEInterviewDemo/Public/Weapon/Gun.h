// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;

UCLASS()
class UEINTERVIEWDEMO_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USkeletalMeshComponent> WeaponSkeletalMesh;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UNiagaraComponent> FireEffect;

	UFUNCTION(BlueprintPure)
	int GetWeaponSize();

	UFUNCTION(BlueprintCallable)
	void DestroyWeapon();

	UFUNCTION(BlueprintImplementableEvent)
	void ImplementThisFunctionInBlueprint();
};
