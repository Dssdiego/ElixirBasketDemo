/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/SystemEditor.h"

#include "../Components/Ball.h"
#include "../Components/ThrowLineLimit.h"

#include "../Archetypes/BallArchetype.h"
#include "../Archetypes/HitMissArchetype.h"

#include "../Source/Input/Mouse.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	struct BallSpawnSystem { };
}

namespace Elixir
{
	using namespace ElixirGame;

	template <>
	void SystemUpdate<BallSpawnSystem>(entt::registry& registry)
	{
		auto view = registry.view<ThrowLineLimit>();

		for (auto entity : view)
		{
			if (!registry.valid(entity))
				return;

			ThrowLineLimit& limit = registry.get<ThrowLineLimit>(entity);

			auto mousePos = Mouse::GetWorldPosition3D();

			if (Mouse::IsButtonPressed(EMouseButton::RIGHT) && mousePos.y <= limit.positionY)
			{
				BallArchetype::Create(mousePos);
				break;
			}
		}
	}
}
