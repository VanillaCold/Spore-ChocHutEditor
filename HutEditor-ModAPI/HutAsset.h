#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore\Sporepedia\AssetData.h>
#include <Spore\Sporepedia\ObjectTemplateDB.h>

#define HutAssetPtr intrusive_ptr<HutAsset>

class HutAsset
	: public Sporepedia::OTDB::ISummarizer
	//: public Sporepedia::cSPAssetDataOTDB //Sporepedia::IAssetData
	//, public DefaultRefCounted
{
public:
	static const uint32_t ID = id("HutAsset");
	
	HutAsset();
	~HutAsset();
	//bool IsShareable();
	//uint32_t GetAssetSubtype();
	//bool IsViewableLarge();
	//bool IsEditable();

	uint32_t GetID() const override;
	int GetAMTuningVersion() const override;
	int GetAssetTypesCount() const override;
	uint32_t GetAssetType(int index) const override;
	bool SetParameters(const ResourceKey& key, vector<Sporepedia::OTDB::Parameter>& dst);

	int AddRef();
	int Release();
	//void* Cast(uint32_t type) const;
};
