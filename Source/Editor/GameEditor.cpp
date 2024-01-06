/*
* Created by Diego S. Seabra on 2023-10-08
*/

#include "GameEditor.h"

#include <imgui/imgui.h>

#include "../Source/Logging/Logger.h"

using namespace Elixir;
//using namespace ElixirGame;
using namespace ElixirGameEditor;

void GameEditor::DrawMainMenuBar()
{
	//if (ImGui::BeginMenu("Alchymia"))
	//{
	//	ImGui::SeparatorText("Game");

	//	if (ImGui::MenuItem("Reset Game", nullptr))
	//	{
	//		Alchymia::CreateWorld();
	//	}

	//	ImGui::SeparatorText("Cards");

	//	if (ImGui::MenuItem("Create Card", nullptr))
	//	{
	//		CardArchetype::Create(ECardElement::AIR, ECardState::NORMAL, glm::vec3(0.f), true);
	//	}

	//	//if (ImGui::MenuItem("Destroy All Cards", nullptr)) { }

	//	if (ImGui::MenuItem("Shuffle Deck", nullptr))
	//		Logger::Warn(ELogContext::GAME, "'Shuffle Deck' is not implemented!");
	//
	//	ImGui::EndMenu();
	//}
}
