/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/ECS.h"
#include "../Source/ECS/Components/Sprite.h"
#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Components/Hitbox.h"
#include "../Source/ECS/Components/TweenPosition.h"

#include "../Components/Basket.h"

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
			auto scale = glm::vec3(1.5f, 1.1f, 1.f);

			auto positionInit = glm::vec3(0.f, 2.5f, -1.f);
			auto positionMaxRight = glm::vec3(6.f, 2.5f, -1.f);
			auto positionMaxLeft = glm::vec3(-6.f, 2.5f, -1.f);

			auto basket = ECS::Create("Basket");

			Sprite sprite;
			sprite.pipeline = "sprite";
			sprite.textureName = "basket";
			sprite.tile = 0;

			WorldTransform worldTransform;
			worldTransform.position = positionInit;
			worldTransform.scale = scale;

			Hitbox hitbox;
			hitbox.color = Color::Green;
			hitbox.size = scale;

			Basket basketComp;
			basketComp.speed = 1.f;

			//TweenPosition tweenPos;
			//tweenPos.duration = 5.f / basketComp.speed;
			//tweenPos.origin = positionInit;
			//tweenPos.target = positionMaxRight;

			ECS::AddComponent(basket, sprite);
			ECS::AddComponent(basket, worldTransform);
			ECS::AddComponent(basket, hitbox);
			//ECS::AddComponent(basket, tweenPos);
			ECS::AddComponent(basket, Basket{});

			return basket;
		}
	};
}
