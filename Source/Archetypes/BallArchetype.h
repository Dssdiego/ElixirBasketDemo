/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/ECS.h"
#include "../Source/ECS/Components/Sprite.h"
#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Components/Hitbox.h"
#include "../Source/ECS/Components/Gravity.h"

#include "../Components/Ball.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	using namespace Elixir;

	class BallArchetype
	{
	public:

		BallArchetype() = delete;

		inline static entt::entity Create(glm::vec3 position)
		{
			auto ball = ECS::Create("Ball");

			Sprite sprite;
			sprite.pipeline = "sprite";
			sprite.textureName = "ball";
			sprite.tile = 0;

			WorldTransform worldTransform;
			worldTransform.position = position;

			Hitbox hitbox;
			hitbox.color = Color::Red;

			Gravity gravity;
			gravity.value = 200.f;
			gravity.useAcceleration = true;

			ECS::AddComponent(ball, sprite);
			ECS::AddComponent(ball, worldTransform);
			ECS::AddComponent(ball, hitbox);
			ECS::AddComponent(ball, gravity);
			ECS::AddComponent(ball, Ball{});

			return ball;
		}
	};
}
