/*
* Created by Diego S. Seabra on 2024-01-06
*/

#include "BasketGame.h"

#include "../Source/ECS/ECS.h"
#include "../Source/Color/Color.h"

#include "Archetypes/ScoreArchetype.h"
#include "Archetypes/BasketArchetype.h"
#include "Archetypes/ThrowLineLimitArchetype.h"

using namespace Elixir;
using namespace ElixirGame;

void BasketGame::CreateWorld()
{
	// Clear the world before initializing it
	ECS::DestroyAll();

	BasketArchetype::Create();
	ThrowLineLimitArchetype::Create();

	ScoreArchetype::Create();

	//GameLimitArchetype::Create(glm::vec3(7.f, 0.f, 0.f), "Right");
	//GameLimitArchetype::Create(glm::vec3(-7.f, 0.f, 0.f), "Left");
}

