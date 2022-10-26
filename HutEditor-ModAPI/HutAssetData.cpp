#include "stdafx.h"
#include "HutAssetData.h"

Sporepedia::cSPAssetDataOTDB* HutAssetData::Factory()
{
	return AssetFactory;
}

HutAssetData::HutAssetData()
{
}


HutAssetData::~HutAssetData()
{
}

ResourceKey HutAssetData::GetBackgroundImageKey()
{
	return { 0x94857B2C,TypeIDs::png,GroupIDs::AssetBrowserGraphics };
}

// For internal use, do not modify.
int HutAssetData::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int HutAssetData::Release()
{
	return DefaultRefCounted::Release();
}

bool HutAssetData::IsViewableLarge()
{
	return true;
}

bool HutAssetData::IsEditable()
{
	return true;
}

// You can extend this function to return any other types your class implements.
void* HutAssetData::Cast(uint32_t type) const
{
	PARENT_CAST(cSPAssetDataOTDB);
	CLASS_CAST(HutAssetData);
	return nullptr;
}

HutAssetData* HutAssetData::AssetFactory;