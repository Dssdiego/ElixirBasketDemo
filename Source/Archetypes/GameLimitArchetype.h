/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/ECS.h"
#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Components/Hitbox.h"

#include "../Components/GameLimit.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	using namespace Elixir;

	class GameLimitArchetype
	{
	public:

		GameLimitArchetype() = delete;

		inline static entt::entity Create(glm::vec3 position, const std::string& name)
		{
			auto limit = ECS::Create("Limit - " + name);

			auto scale = glm::vec3(0.25f, 10.f, 0.f);

			WorldTransform worldTransform;
			worldTransform.position = position;
			worldTransform.scale = scale;

			Hitbox hitbox;
			hitbox.color = Color::Red;
			hitbox.size = scale;

			ECS::AddComponent(limit, worldTransform);
			ECS::AddComponent(limit, hitbox);
			ECS::AddComponent(limit, GameLimit{});

			return limit;
		}
	};
}
