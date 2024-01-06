/*
* Created by Diego S. Seabra on 2023-12-23
*/

#pragma once

#include "../Source/ECS/ECS.h"

#include "../Source/ECS/ECS.h"
#include "../Source/ECS/Components/Sprite.h"
#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Components/Hitbox.h"

#include "../Components/DVD.h"

#include <entt/entt.hpp>

namespace ElixirGame
{
	using namespace Elixir;

	class LogoArchetype
	{
	public:

		LogoArchetype() = delete;

		// NOTE: Always creating on the (0,0,0)
		inline static entt::entity Create()
		{
			auto logo = ECS::Create("DVD Logo");

			Sprite sprite;
			sprite.pipeline = "sprite";
			sprite.textureName = "dvd_logo";
			sprite.tile = 0;
			sprite.visible = true;

			WorldTransform worldTransform;
			worldTransform.position = glm::vec3(0.f);
			worldTransform.scale = DVDLogo::LogoScale;

			Hitbox hitbox;
			hitbox.size = DVDLogo::LogoScale;
			hitbox.color = Color::Purple;

			ECS::AddComponent(logo, sprite);
			ECS::AddComponent(logo, worldTransform);
			ECS::AddComponent(logo, hitbox);
			ECS::AddComponent(logo, DVD{});

			return logo;
		}
	};
}
