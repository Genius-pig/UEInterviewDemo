// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GCTestActor.generated.h"

UCLASS()
class UGarbageCollectableObject : public UObject
{
	GENERATED_BODY()
	
};

UCLASS()
class UEINTERVIEWDEMO_API AGCTestActor : public AActor
{
	GENERATED_BODY()

public:
	AGCTestActor();

	UGarbageCollectableObject* RawObject = nullptr;

	TWeakObjectPtr<UGarbageCollectableObject> WeakPtrToRaw = nullptr;

	UPROPERTY()
	UGarbageCollectableObject* PropertySafeObject = nullptr;

	UPROPERTY()
	TObjectPtr<UGarbageCollectableObject> ObjPtrPropertySafeObject = nullptr;

	void CreateObjects();
	void PrintObjectPointerState() const;
	void UseRawObject() const;

	void ForceGarbageCollectionOfProperties() const;
	
};
