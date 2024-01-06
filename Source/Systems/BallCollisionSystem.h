/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/SystemEditor.h"

#include "../Source/ECS/Systems/CollisionSystem.h"

#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Components/Hitbox.h"

#include "../Components/Ball.h"
#include "../Components/Basket.h"

#include "../Archetypes/HitMissArchetype.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	using namespace Elixir;

	struct BallCollisionSystem { };
}

namespace Elixir
{
	using namespace ElixirGame;

	template <>
	void SystemUpdate<BallCollisionSystem>(entt::registry& registry)
	{
		auto basketEntity = registry.view<Basket>()[0];

		if (!registry.valid(basketEntity))
			return;

		//Hitbox& basketHitbox = registry.get<Hitbox>(basketEntity);

		// Iterate for all the ball entities to check the collision against the basket
		auto ballView = registry.view<Ball>();
		for (auto ballEntity : ballView)
		{
			if (!registry.valid(ballEntity))
				return;

			Ball& ball = registry.get<Ball>(ballEntity);
			//Hitbox& ballHitbox = registry.get<Hitbox>(ballEntity);
			WorldTransform& ballWorldTransform = registry.get<WorldTransform>(ballEntity);

			if (CollisionSystem::CheckCollision(registry, basketEntity, ballEntity))
			{
				HitMissArchetype::Create(ballWorldTransform.position, EHitMissType::HIT);
				ECS::Destroy(ballEntity);
			}
		}
	}
}
