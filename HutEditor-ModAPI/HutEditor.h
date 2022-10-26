#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore\Creations.h>
#include <Spore\Cheats.h>

class HutEditor 
	: public ArgScript::ICommand
	, public Sporepedia::IShopperListener
//, public Sporepedia::ShopperRequest
{
public:
	HutEditor();
	~HutEditor();

	// Called when the cheat is invoked
	void ParseLine(const ArgScript::Line& line) override;

	void OnShopperAccept(const ResourceKey& selection) override;
	// Returns a string containing the description. If mode != DescriptionMode::Basic, return a more elaborated description
	const char* GetDescription(ArgScript::DescriptionMode mode) const override;
};

