// Fill out your copyright notice in the Description page of Project Settings.


#include "GC/GCTestActor.h"

#include "EngineUtils.h"
#include "Kismet/KismetSystemLibrary.h"

static FAutoConsoleCommandWithWorldAndArgs CmdGCTest_CreateObjects(
	TEXT("gc.test.createObjects"),
	TEXT(""),
	FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, const UWorld* World)
	{
		for(TActorIterator<AGCTestActor> GCTestIterator(World); GCTestIterator; ++GCTestIterator)
		{
			if(AGCTestActor* GCTest = Cast<AGCTestActor>(*GCTestIterator))
			{
				GCTest->CreateObjects();
			}
		}
	})
	);

static FAutoConsoleCommandWithWorldAndArgs CmdGCTest_PrintObjects(
	TEXT("gc.test.printObjects"),
	TEXT(""),
	FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, const UWorld* World)
	{
		for(TActorIterator<AGCTestActor> GCTestIterator(World); GCTestIterator; ++GCTestIterator)
		{
			if(const AGCTestActor* GCTest = Cast<AGCTestActor>(*GCTestIterator))
			{
				GCTest->PrintObjectPointerState();
			}
		}
	})
	);

static FAutoConsoleCommandWithWorldAndArgs CmdGCTest_UseRawObject(
	TEXT("gc.test.useRawObject"),
	TEXT(""),
	FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, const UWorld* World)
	{
		for(TActorIterator<AGCTestActor> GCTestIterator(World); GCTestIterator; ++GCTestIterator)
		{
			if(const AGCTestActor* GCTest = Cast<AGCTestActor>(*GCTestIterator))
			{
				GCTest->UseRawObject();
			}
		}
	})
	);

static FAutoConsoleCommandWithWorldAndArgs CmdGCTest_ForceGarbageCollectionOfProperties(
	TEXT("gc.test.ForceGarbageCollectionOfProperties"),
	TEXT(""),
	FConsoleCommandWithWorldAndArgsDelegate::CreateLambda([](const TArray<FString>& Args, const UWorld* World)
	{
		for(TActorIterator<AGCTestActor> GCTestIterator(World); GCTestIterator; ++GCTestIterator)
		{
			if(const AGCTestActor* GCTest = Cast<AGCTestActor>(*GCTestIterator))
			{
				GCTest->ForceGarbageCollectionOfProperties();
			}
		}
	})
	);


// Sets default values
AGCTestActor::AGCTestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

void AGCTestActor::CreateObjects()
{
	RawObject = NewObject<UGarbageCollectableObject>();
	WeakPtrToRaw = RawObject;

	PropertySafeObject = NewObject<UGarbageCollectableObject>();
	ObjPtrPropertySafeObject = NewObject<UGarbageCollectableObject>();
}

void AGCTestActor::PrintObjectPointerState() const
{
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s RawObject %p"), ANSI_TO_TCHAR(__FUNCTION__), RawObject), true, true, FLinearColor::Green, 5.0f);
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s WeakPtrToRaw %i"), ANSI_TO_TCHAR(__FUNCTION__), WeakPtrToRaw.IsValid()), true, true, FLinearColor::Green, 5.0f);
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s PropertySafeObject %p"), ANSI_TO_TCHAR(__FUNCTION__), PropertySafeObject), true, true, FLinearColor::Green, 5.0f);
	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("%s ObjPtrPropertySafeObject %p"), ANSI_TO_TCHAR(__FUNCTION__), ObjPtrPropertySafeObject.Get()), true, true, FLinearColor::Green, 5.0f);
}

void AGCTestActor::UseRawObject() const
{
	if(RawObject)
	{
		UE_LOG(LogTemp, Log, TEXT("%hs - Using RawObject %s"), ANSI_TO_TCHAR(__FUNCTION__), *GetNameSafe(RawObject));
		UE_LOG(LogTemp, Log, TEXT("%hs - Using WeakPtrToRaw %s"), ANSI_TO_TCHAR(__FUNCTION__), *WeakPtrToRaw->GetName());
	}
}

void AGCTestActor::ForceGarbageCollectionOfProperties() const
{
	if(PropertySafeObject)
	{
		PropertySafeObject->MarkAsGarbage();
	}
	if(ObjPtrPropertySafeObject)
	{
		ObjPtrPropertySafeObject->MarkAsGarbage();
	}
}

