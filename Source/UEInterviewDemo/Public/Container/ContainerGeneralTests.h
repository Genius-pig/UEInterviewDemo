// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ContainerGeneralTests.generated.h"

UCLASS()
class UEINTERVIEWDEMO_API AContainerGeneralTests : public AActor
{
	GENERATED_BODY()

public:
	AContainerGeneralTests();

	TArray<FName> CodeNameArray;

	virtual void BeginPlay() override;
};
