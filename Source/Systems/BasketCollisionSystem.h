/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/SystemEditor.h"

#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Systems/CollisionSystem.h"

#include "../Components/Basket.h"
#include "../Components/GameLimit.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	struct [[deprecated]] BasketCollisionSystem { };
}

namespace Elixir
{
	using namespace ElixirGame;

	template <>
	void SystemUpdate<BasketCollisionSystem>(entt::registry& registry)
	{
		//auto basketEntity = registry.view<Basket>()[0];

		//if (!registry.valid(basketEntity))
		//	return;

		//Basket& basket = registry.get<Basket>(basketEntity);
		//WorldTransform& basketWorldTransform = registry.get<WorldTransform>(basketEntity);

		////if (worldTransform.position.x > 6.f || worldTransform.position.x < -6.f)
		//	//{
		//	//	basket.directionX *= -1;
		//	//	return;
		//	//}

		//// Iterate for all the GameLimit entities to check the collision against the basket
		//auto limitView = registry.view<GameLimit>();
		//for (auto limitEntity : limitView)
		//{
		//	if (!registry.valid(limitEntity))
		//		return;

		//	GameLimit& limit = registry.get<GameLimit>(limitEntity);
		//	//WorldTransform& limitWorldTransform = registry.get<WorldTransform>(ballEntity);

		//	if (CollisionSystem::CheckCollision(registry, basketEntity, limitEntity))
		//	{
		//		basket.directionX *= -1;
		//		return;
		//	}
		//}
	}
}
