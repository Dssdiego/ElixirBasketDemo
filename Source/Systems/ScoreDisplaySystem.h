/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/SystemEditor.h"

#include "../Source/ECS/Components/Text.h"

#include "../Components/Score.h"

#include "../Systems/GameDifficultySystem.h"

#include <entt/entt.hpp>
#include <format>

namespace ElixirGame
{
	struct ScoreDisplaySystem { };
}

namespace Elixir
{
	using namespace ElixirGame;

	template <>
	void SystemUpdate<ScoreDisplaySystem>(entt::registry& registry)
	{
		auto view = registry.view<Score>();

		for (auto entity : view)
		{
			if (!registry.valid(entity))
				return;

			Score& score = registry.get<Score>(entity);
			score.value = static_cast<uint32_t>(GameDifficultySystem::GetLevel());

			Text& text = registry.get<Text>(entity);
			text.text = std::format("{:.0f}", score.value);
		}
	}
}

