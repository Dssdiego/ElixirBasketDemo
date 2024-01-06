/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/SystemEditor.h"

#include "../Components/Basket.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	using namespace Elixir;

	struct BasketMovementSystem { };
}

namespace Elixir
{
	using namespace ElixirGame;

	template <>
	void SystemUpdate<BasketMovementSystem>(entt::registry& registry)
	{
		auto view = registry.view<Basket>();

		for (auto entity : view)
		{
			if (!registry.valid(entity))
				return;

			Basket& basket = registry.get<Basket>(entity);

		}
	}
}
