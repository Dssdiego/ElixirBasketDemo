/*
* Created by Diego S. Seabra on 2023-12-26
*/

#include "DVDLogo.h"

#include "../Source/ECS/ECS.h"
#include "../Source/Color/Color.h"

#include "Archetypes/LogoArchetype.h"

using namespace Elixir;
using namespace ElixirGame;

void DVDLogo::CreateWorld()
{
	// Clear the world before initializing it
	ECS::DestroyAll();

	// Creating the DVD Logo
	LogoArchetype::Create();
}

//void Alchymia::CreateCards()
//{
//	auto randTL = static_cast<ECardElement>(RandomGenerator::RandomInt(0, 3));
//	CardArchetype::Create(randTL, ECardState::NORMAL, slotTLPosition, true);
//
//	auto randTM = static_cast<ECardElement>(RandomGenerator::RandomInt(0, 3));
//	CardArchetype::Create(randTM, ECardState::NORMAL, slotTMPosition, true);
//
//	auto randTR = static_cast<ECardElement>(RandomGenerator::RandomInt(0, 3));
//	CardArchetype::Create(randTR, ECardState::NORMAL, slotTRPosition, true);
//
//	auto randBL = static_cast<ECardElement>(RandomGenerator::RandomInt(0, 3));
//	CardArchetype::Create(randBL, ECardState::NORMAL, slotBLPosition, true);
//
//	auto randBM = static_cast<ECardElement>(RandomGenerator::RandomInt(0, 3));
//	CardArchetype::Create(randBM, ECardState::NORMAL, slotBMPosition, true);
//
//	auto randBR = static_cast<ECardElement>(RandomGenerator::RandomInt(0, 3));
//	CardArchetype::Create(randBR, ECardState::NORMAL, slotBRPosition, true);
//
//	//auto cardPosition = stackOrigin;
//
//	// 36 cards
//	/*for (size_t y = 0; y < 6; y++)
//	{
//		for (size_t x = 0; x < 6; x++)
//		{
//			CreateCard(static_cast<ECardValue>(RandomGenerator::RandomInt(0, 7, 12092023)), ECardState::NORMAL, cardPosition);
//			cardPosition.x += cardOffset.x;
//		}
//		cardPosition.x = stackOrigin.x;
//	// We need to init the game stuff before initializing the engine so that our assets (such as textures) are created before
//		cardPosition.y += cardOffset.y;
//		cardPosition.z -= cardOffset.z;
//	}*/
//}
//
//void Alchymia::CreateCardSlots()
//{
//	CardSlotArchetype::Create("TL", slotTLPosition);
//	CardSlotArchetype::Create("TM", slotTMPosition);
//	CardSlotArchetype::Create("TR", slotTRPosition);
//
//	CardSlotArchetype::Create("BL", slotBLPosition);
//	CardSlotArchetype::Create("BM", slotBMPosition);
//	CardSlotArchetype::Create("BR", slotBRPosition);
//}
//
//void Alchymia::CreateChallenge()
//{
//	challenge = ChallengeSystem::Generate();
//}
//
//void Alchymia::CreateButtons()
//{
//	ButtonArchetype::Create<&Alchymia::CreateWorld>("New Game", 0, glm::vec3(-3.25f, 0.75f, 0.f));
//
//	ButtonArchetype::Create<&Alchymia::ShowLeaderboard>("Leaderboards", 2, glm::vec3(-3.25f, 1.2f, 0.f), false);
//
//	ButtonArchetype::Create<&Alchymia::ShowSettings>("Settings", 3, glm::vec3(-3.25f, 1.65f, 0.f), false);
//
//	ButtonArchetype::Create<&Alchymia::TEMP_Transmutation>("Transmutation", 1, glm::vec3(3.25f, 1.65f, 0.f));
//}
//
//void Alchymia::ShowLeaderboard()
//{
//	Logger::Warn(ELogContext::GAME, "Show leaderboard is not implemented yet!");
//}
//
//void Alchymia::ShowSettings()
//{
//	Logger::Warn(ELogContext::GAME, "Show settings is not implemented yet!");
//}
//
//void Alchymia::TEMP_Transmutation()
//{
//	Logger::Warn(ELogContext::GAME, "Transmutation is not implemented yet!");
//}

