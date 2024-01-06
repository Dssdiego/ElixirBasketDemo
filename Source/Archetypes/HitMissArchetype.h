/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/ECS.h"
#include "../Source/ECS/Components/Sprite.h"
#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Components/Hitbox.h"
#include "../Source/ECS/Components/TweenPosition.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	using namespace Elixir;

	enum class EHitMissType
	{
		HIT,
		MISS
	};

	class HitMissArchetype
	{
	public:

		HitMissArchetype() = delete;

		inline static entt::entity Create(glm::vec3 position, EHitMissType type)
		{
			auto hitMiss = ECS::Create("Hit/Miss");

			Sprite sprite;
			sprite.pipeline = "sprite";

			if (type == EHitMissType::HIT)
				sprite.textureName = "hit";
			else
				sprite.textureName = "miss";

			WorldTransform worldTransform;
			worldTransform.position = position;

			Hitbox hitbox;
			hitbox.color = Color::Yellow;

			TweenPosition tweenPos;
			tweenPos.duration = 0.2f;
			tweenPos.origin = position;
			tweenPos.target = glm::vec3(position.x, position.y - 0.25f, position.z);
			tweenPos.onTweenEnded.connect<&OnTweenEnded>();

			ECS::AddComponent(hitMiss, sprite);
			ECS::AddComponent(hitMiss, worldTransform);
			ECS::AddComponent(hitMiss, hitbox);
			ECS::AddComponent(hitMiss, tweenPos);

			return hitMiss;
		}

		inline static void OnTweenEnded(entt::entity entity)
		{
			if (!ECS::GetRegistryRef().valid(entity))
				return;

			ECS::Destroy(entity);
		}
	};
}
