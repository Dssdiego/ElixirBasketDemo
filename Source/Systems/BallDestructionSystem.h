/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/SystemEditor.h"

#include "../Components/Ball.h"
#include "../Archetypes/HitMissArchetype.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	struct BallDestructionSystem { };
}

namespace Elixir
{
	using namespace ElixirGame;

	template <>
	void SystemUpdate<BallDestructionSystem>(entt::registry& registry)
	{
		auto view = registry.view<Ball>();

		for (auto entity : view)
		{
			if (!registry.valid(entity))
				return;

			Ball& ball = registry.get<Ball>(entity);
			Sprite& sprite = registry.get<Sprite>(entity);

			WorldTransform& worldTransform = registry.get<WorldTransform>(entity);
			
			// If the ball hits the bottom of the screen, it gets destroyed
			// And then we create the "Miss" image
			if (worldTransform.position.y > 3.5f)
			{
				HitMissArchetype::Create(worldTransform.position, EHitMissType::MISS);
				ECS::Destroy(entity);
			}
		}
	}
}

