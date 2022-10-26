#include "stdafx.h"
#include "SwapHut.h"
#include <Spore\Simulator\cPlayer.h>
#include <Spore\Editors\BakeManager.h>

//using namespace Simulator;
SwapHut::SwapHut()
{
	sInstance = this;
}


SwapHut::~SwapHut()
{
	sInstance = nullptr;
}


SwapHut* SwapHut::Get()
{
	return sInstance;
}

void SwapHut::ParseLine(const ArgScript::Line& line)
{
	if (Simulator::IsTribeGame()) 
	{		
		//auto thing = SpacePlayerData::Get();
		//App::ConsolePrintF(to_string(thing->mPlayerEmpireID).c_str());
		//GameNounManager.mpPlayerTribe
		//SporeDebugPrint("%u",cGameNounManager_addresses::Get);
		
		auto args = line.GetArguments(3);

		angle = Vector3(mpFormatParser->ParseInt(args[0]), mpFormatParser->ParseInt(args[1]), mpFormatParser->ParseInt(args[2]));

		auto request = Sporepedia::ShopperRequest(this);
		request.shopperID == id("hut_shopper");
		request.Show(request);

	}
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
}

/*member_detour(Chocice75_HutEditor_SwapHutModelDetour, Graphics::IModelWorld, Graphics::Model* (uint32_t instanceID, uint32_t groupID, int arg_8))
{
	Graphics::Model* detoured(uint32_t instanceID,uint32_t groupID,int arg_8)
	{
		ResourceKey HutModel = SwapHut::Get()->HutModelKey;
		if (IsTribeGame() && instanceID == (id("he_simple_1") || id("he_simple_2")) && groupID == 0x2BE764E2 && HutModel.instanceID != 0)
		{
			return original_function(this, HutModel.instanceID, HutModel.groupID, arg_8);
		}
			
		else return original_function(this,instanceID,groupID,arg_8);
	}
};*/

void SwapHut::AttachDetours()
{
	//Chocice75_HutEditor_SwapHutModelDetour::attach((GetAddress(Graphics::IModelWorld, LoadModelProperties)-0x178)+0x0C);
}

const char* SwapHut::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat does something.";
	}
	else {
		return "SwapHut: Elaborate description of what this cheat does.";
	}
}

void SwapHut::OnShopperAccept(const ResourceKey& selection)
{
	PropertyListPtr propList;
	if (!PropManager.GetPropertyList(selection.instanceID, selection.groupID, propList))
	{
		BakeManager.func4Ch(selection, NULL);
	}
		HutModelKey = selection;
		SporeDebugPrint("0");
		//for (auto creature : Simulator::GetData<Simulator::cCreatureAnimal>())
		
		for (cTribePtr tribe : Simulator::GetDataByCast<Simulator::cTribe>())
		{
			SporeDebugPrint("1");

			auto hut = tribe->mpHut;
			hut->SetModelKey(selection);
			hut->mUndamagedModel = selection;
			hut->SetScale(2);
		}
}

SwapHut* SwapHut::sInstance;