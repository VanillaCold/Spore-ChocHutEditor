#include "stdafx.h"
#include "HutAsset.h"

HutAsset::HutAsset()
{
}


HutAsset::~HutAsset()
{
}


uint32_t HutAsset::GetID() const
{
	return ID;
}

int HutAsset::GetAMTuningVersion() const
{
	return 1;
}

int HutAsset::GetAssetTypesCount() const
{
	return 1;
}

uint32_t HutAsset::GetAssetType(int index) const
{
	return id("hut");
}

bool HutAsset::SetParameters(const ResourceKey& key, vector<Sporepedia::OTDB::Parameter>& dst)
{
	if (key.typeID == id("hut"))
	{
		dst.push_back(Sporepedia::OTDB::Parameter::Int(Sporepedia::OTDB::Parameters::type, id("hut")));
		dst.push_back(Sporepedia::OTDB::Parameter::Int(Sporepedia::OTDB::Parameters::subtype, id("hut")));
		return true;
	}
	return false;
}

// For internal use, do not modify.
int HutAsset::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int HutAsset::Release()
{
	return DefaultRefCounted::Release();
}

// You can extend this function to return any other types your class implements.
/*/void* HutAsset::Cast(uint32_t type) const
{
	CLASS_CAST(Object);
	//CLASS_CAST(HutAsset);
	return nullptr;
}
*/