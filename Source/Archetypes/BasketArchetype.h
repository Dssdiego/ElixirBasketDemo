/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/ECS.h"
#include "../Source/ECS/Components/Sprite.h"
#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Components/Hitbox.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	using namespace Elixir;

	class BasketArchetype
	{
	public:

		BasketArchetype() = delete;

		inline static entt::entity Create()
		{
			auto basket = ECS::Create("Basket");

			Sprite sprite;
			sprite.pipeline = "sprite";
			sprite.textureName = "basket";
			sprite.tile = 0;

			WorldTransform worldTransform;
			worldTransform.position = glm::vec3(0.f);
			//worldTransform.scale = DVDLogo::LogoScale;

			Hitbox hitbox;
			//hitbox.size = DVDLogo::LogoScale;
			hitbox.color = Color::Green;

			ECS::AddComponent(basket, sprite);
			ECS::AddComponent(basket, worldTransform);
			ECS::AddComponent(basket, hitbox);
			//ECS::AddComponent(logo, DVD{});

			return basket;
		}
	};
}
