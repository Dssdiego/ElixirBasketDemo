/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/SystemEditor.h"

#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Components/Hitbox.h"

#include "../Components/ThrowLineLimit.h"

#include "../Systems/GameDifficultySystem.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	using namespace Elixir;

	struct LinePositionSystem { };
}

namespace Elixir
{
	using namespace ElixirGame;

	template <>
	void SystemUpdate<LinePositionSystem>(entt::registry& registry)
	{
		auto lineEntity = registry.view<ThrowLineLimit>()[0];

		if (!registry.valid(lineEntity))
			return;

		ThrowLineLimit& limit = registry.get<ThrowLineLimit>(lineEntity);
		WorldTransform& lineWorldTransform = registry.get<WorldTransform>(lineEntity);

		limit.positionY = limit.initialY - (GameDifficultySystem::GetLevel() / 5.f);

		lineWorldTransform.position = glm::vec3(0.f, limit.positionY, 0.f);
	}
}
