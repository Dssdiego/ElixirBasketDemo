/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/ECS.h"
#include "../Source/ECS/Components/Sprite.h"
#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Components/Hitbox.h"

#include "../Components/ThrowLineLimit.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	using namespace Elixir;

	class ThrowLineLimitArchetype
	{
	public:

		ThrowLineLimitArchetype() = delete;

		inline static entt::entity Create()
		{
			auto scale = glm::vec3(20.f, 0.05f, 1.f);

			auto line = ECS::Create("Throw Line Limit");

			ThrowLineLimit lineComp;
			lineComp.positionY = 1.5f;

			Sprite sprite;
			sprite.pipeline = "sprite";
			sprite.textureName = "line";
			sprite.tile = 0;

			WorldTransform worldTransform;
			worldTransform.position = glm::vec3(0.f, lineComp.positionY, 0.f);
			worldTransform.scale = scale;

			Hitbox hitbox;
			hitbox.color = Color::Purple;
			hitbox.size = scale;

			ECS::AddComponent(line, sprite);
			ECS::AddComponent(line, worldTransform);
			ECS::AddComponent(line, hitbox);
			ECS::AddComponent(line, lineComp);

			return line;
		}
	};
}
