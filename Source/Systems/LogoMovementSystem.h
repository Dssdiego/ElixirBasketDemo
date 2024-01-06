/*
* Created by Diego S. Seabra on 2023-09-04
*/

#pragma once

#include "../Source/ECS/ECS.h"
#include "../Source/ECS/SystemEditor.h"
#include "../Source/ECS/Components/Sprite.h"
#include "../Source/ECS/Components/WorldTransform.h"

#include "../Source/Audio/AudioSystem.h"

#include "../Source/Time/Time.h"

#include <vector>
#include <entt/entt.hpp>

#include "../Components/DVD.h"

namespace ElixirGame
{
	using namespace Elixir;

	struct LogoMovementSystem {};
}

namespace Elixir
{
	using namespace ElixirGame;

	template <>
	void SystemUpdate<LogoMovementSystem>(entt::registry& registry)
	{
		auto view = registry.view<DVD>();

		for (auto entity : view)
		{
			if (!registry.valid(entity))
				return;

			DVD& dvdLogo = registry.get<DVD>(entity);

			WorldTransform& worldTransform = registry.get<WorldTransform>(entity);
			worldTransform.position += (dvdLogo.direction * dvdLogo.speed * (float) Time::Delta);
		}
	}
}
