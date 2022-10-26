#include "stdafx.h"
#include "HutEditor.h"
#include <Spore\Sporepedia\IShopperListener.h>
#include <Spore\Sporepedia\ShopperRequest.h>
#include "MyWinProc.h"

HutEditor::HutEditor()
{
}


HutEditor::~HutEditor()
{
}

void HutEditor::ParseLine(const ArgScript::Line& line)
{
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
	//Sporepedia::ShopperRequest request(this);
	//Sporepedia::ShopperRequest::Show(request);
	
	//UILayout layout;
	//layout.LoadByName(u"GlobalUIGGE-9-EP1");
	//layout.SetParentWindow(WindowManager.GetMainWindow());
	//auto hutbutton = WindowManager.GetMainWindow()->FindWindowByID(id("HutButton"));
	//hutbutton->AddWinProc(new MyWinProc);
	
	EditorRequestPtr request = new Editors::EditorRequest();
	request->editorID = id("huteditor");
	request->allowSporepedia = false;
	request->hasSaveButton = true;
	request->sporepediaCanSwitch = false;
	request->hasPublishButton = false;
	request->hasCreateNewButton = true;
	auto thingy = Simulator::cGameModeManager::Get();
	thingy->SubmitEditorRequest(request.get());
}

const char* HutEditor::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat does something.";
	}
	else {
		return "HutEditor: Elaborate description of what this cheat does.";
	}
}

void HutEditor::OnShopperAccept(const ResourceKey& selection)
{

	/*cAssetMetadataPtr metadata;
	Pollinator::GetMetadata(selection.instanceID, selection.groupID, metadata);
	App::ConsolePrintF("You selected the creation %ls", metadata->GetName().c_str());*/

}