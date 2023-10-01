// Fill out your copyright notice in the Description page of Project Settings.


#include "GC/GCTestActor.h"

#include "Kismet/KismetStringLibrary.h"
#include "Kismet/KismetSystemLibrary.h"


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

void AGCTestActor::UseRawObject()
{
	if(RawObject)
	{
		UE_LOG(LogTemp, Log, TEXT("%hs - Using RawObject %s"), ANSI_TO_TCHAR(__FUNCTION__), *GetNameSafe(RawObject));
		UE_LOG(LogTemp, Log, TEXT("%hs - Using WeakPtrToRaw %s"), ANSI_TO_TCHAR(__FUNCTION__), *WeakPtrToRaw->GetName());
	}
}

void AGCTestActor::ForceGarbageCollectionOfProperties()
{
	if(PropertySafeObject)
	{
		PropertySafeObject->MarkAsGarbage();
	}
	if(ObjPtrPropertySafeObject)
	{
		
	}
}

