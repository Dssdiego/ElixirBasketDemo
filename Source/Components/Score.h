/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/EntityEditor.h"
#include "../Source/Editor/EditorDraw.h"

namespace ElixirGame
{
	struct Score
	{
		float value = 0.f;

		/* Serialization */
		template<class Archive>
		void serialize(Archive& archive)
		{
			archive(value);
		}
	};
}

namespace Elixir
{
	using namespace ElixirEditor;
	using namespace ElixirGame;

	/* Draw component in editor */
	template <>
	void EditorWidget<Score>(entt::registry& registry, entt::entity entity)
	{
	}
}
