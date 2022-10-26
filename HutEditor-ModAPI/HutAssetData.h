#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore\Sporepedia\AssetData.h>

#define HutAssetDataPtr intrusive_ptr<HutAssetData>

class HutAssetData 
	: public Sporepedia::cSPAssetDataOTDB
{
public:
	static const uint32_t TYPE = id("HutAssetData");

	static Sporepedia::cSPAssetDataOTDB* Factory();
	
	HutAssetData();
	~HutAssetData();
	//AssetBrowserGraphics!0x94857B2C.png
	ResourceKey GetBackgroundImageKey();
	int AddRef() override;
	int Release() override;
	bool IsViewableLarge();
	bool IsEditable();
	void* Cast(uint32_t type) const override;

	static HutAssetData* AssetFactory;
};
