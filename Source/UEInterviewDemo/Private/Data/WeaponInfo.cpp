// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/WeaponInfo.h"

FGunData UWeaponInfo::FindInfoForID(int32 ID)
{
	for (int i = 0; i < WeaponInfo.Num(); i++)
	{
		if (WeaponInfo[i].WeaponID == ID)
		{
			return WeaponInfo[i];
		}
	}

	return FGunData();
}
