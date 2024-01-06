/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/EntityEditor.h"
#include "../Source/Editor/EditorDraw.h"

#include "../Source/Color/Color.h"

namespace ElixirGame
{
	struct Ball
	{
		float foo = 1.f;

		/* Serialization */
		template<class Archive>
		void serialize(Archive& archive)
		{
			archive(foo);
		}
	};
}

namespace Elixir
{
	using namespace ElixirEditor;
	using namespace ElixirGame;

	/* Draw component in editor */
	template <>
	void EditorWidget<Ball>(entt::registry& registry, entt::entity entity)
	{
	}
}
