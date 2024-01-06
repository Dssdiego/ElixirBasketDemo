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
		float initialY = 0.f;
		float positionY = 0.f;

		/* Serialization */
		template<class Archive>
		void serialize(Archive& archive)
		{
			archive(initialY);
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
