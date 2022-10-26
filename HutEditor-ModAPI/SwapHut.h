#pragma once

#include <Spore\BasicIncludes.h>

class SwapHut 
	: public ArgScript::ICommand
	, public Sporepedia::IShopperListener
{
public:
	SwapHut();
	~SwapHut();

	// Called when the cheat is invoked
	static SwapHut* Get();
	void ParseLine(const ArgScript::Line& line) override;
	
	void AttachDetours();

	// Returns a string containing the description. If mode != DescriptionMode::Basic, return a more elaborated description
	const char* GetDescription(ArgScript::DescriptionMode mode) const override;
	ResourceKey HutModelKey;
	void OnShopperAccept(const ResourceKey& selection) override;

	Vector3 angle = Vector3(0, 0, 0);

protected:
	static SwapHut* sInstance;
};

