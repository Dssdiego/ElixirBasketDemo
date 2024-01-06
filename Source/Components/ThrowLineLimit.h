/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/EntityEditor.h"
#include "../Source/Editor/EditorDraw.h"

namespace ElixirGame
{
	struct ThrowLineLimit
	{
		float positionY = 2.3f;

		/* Serialization */
		template<class Archive>
		void serialize(Archive& archive)
		{
			archive(positionY);
		}
	};
}

namespace Elixir
{
	using namespace ElixirEditor;
	using namespace ElixirGame;

	/* Draw component in editor */
	template <>
	void EditorWidget<ThrowLineLimit>(entt::registry& registry, entt::entity entity)
	{
	}
}
