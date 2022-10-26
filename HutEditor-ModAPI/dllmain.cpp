// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <Spore/Sporepedia/AssetViewManager.h>
#include "MyWinProc.h"
#include "HutEditor.h"
#include <Spore\GalaxyGameEntry\GlobalGGEUI.h>
#include "SwapHut.h"
#include "HutAsset.h"
#include <Spore/Sporepedia/ObjectTemplateDB.h>
#include "HutAssetData.h"

void Initialize()
{
	// This method is executed when the game starts, before the user interface is shown
	// Here you can do things such as:
	//  - Add new cheats
	//  - Add new simulator classes
	//  - Add new game modes
	//  - Add new space tools
	//  - Change materials

	//UILayout layout;
	//layout.LoadByName(u"GlobalUIGGE-9-EP1");
	ObjectTemplateDB.AddSummarizer(new HutAsset());

	HutAssetData::AssetFactory = new HutAssetData();

	AssetViewManager.field_B8->SetAssetDataFactory(id("Hut"), HutAssetData::Factory);

	HutAssetData::AssetFactory->SetParameter(Sporepedia::OTDB::Parameter::Int(Sporepedia::OTDB::Parameters::cost,9999999999));

	ObjectTemplateDB.Write(true, true);

	CheatManager.AddCheat("EnterHutEditorInGame", new HutEditor());
	CheatManager.AddCheat("swaphut", new SwapHut());
}

void Dispose()
{
	// This method is called when the game is closing
}

member_detour(ChocGGE_Detour, GalaxyGameEntry::GlobalGGEUI,
	void())
{
	void detoured()
	{
		// Just call the original on this object
		original_function(this);
		auto hutbutton = WindowManager.GetMainWindow()->FindWindowByID(id("HutButton"));
		hutbutton->AddWinProc(new MyWinProc());
	}
};

void AttachDetours()
{
	SwapHut::Get()->AttachDetours();
	//ChocGGE_Detour::attach(GetAddress(GalaxyGameEntry::GlobalGGEUI,InitializeUI));
	// Call the attach() method on any detours you want to add
	// For example: cViewer_SetRenderType_detour::attach(GetAddress(cViewer, SetRenderType));
}


// Generally, you don't need to touch any code here
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		ModAPI::AddPostInitFunction(Initialize);
		ModAPI::AddDisposeFunction(Dispose);

		PrepareDetours(hModule);
		AttachDetours();
		CommitDetours();
		break;

	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}
