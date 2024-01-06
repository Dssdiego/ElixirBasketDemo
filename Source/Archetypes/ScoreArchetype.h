/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/ECS.h"
#include "../Source/ECS/Components/Sprite.h"
#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Components/Hitbox.h"
#include "../Source/ECS/Components/Text.h"

#include "../Components/Score.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	using namespace Elixir;

	class ScoreArchetype
	{
	public:

		ScoreArchetype() = delete;

		inline static entt::entity Create()
		{
			auto score = ECS::Create("Score");

			auto scale = glm::vec3(2.6f, 1.f, 1.f);

			Sprite sprite;
			sprite.pipeline = "sprite";
			sprite.textureName = "score";
			sprite.tile = 0;

			WorldTransform worldTransform;
			worldTransform.position = glm::vec3(-5.9f, -2.4f, 0.f);
			worldTransform.scale = scale;

			Hitbox hitbox;
			hitbox.color = Color::Blue;
			hitbox.size = scale;

			ECS::AddComponent(score, sprite);
			ECS::AddComponent(score, worldTransform);
			ECS::AddComponent(score, hitbox);

			auto scoreText = ECS::Create("ScoreText");

			Text textComp;
			textComp.text = "00";
			textComp.scale = 0.5f;
			textComp.color = Color::GMB_1;

			Transform textTransform;
			textTransform.position = glm::vec3(0.3f, 0.f, -1.f);

			ECS::AddComponent(scoreText, textComp);
			ECS::AddComponent(scoreText, WorldTransform{});
			ECS::AddComponent(scoreText, textTransform);
			ECS::AddComponent(scoreText, Score{});

			ECS::MakeChildOf(scoreText, score);

			return score;
		}
	};
}
