/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include "../Source/ECS/EntityEditor.h"
#include "../Source/Editor/EditorDraw.h"

namespace ElixirGame
{
	struct Basket
	{
		float speed = 1.f;

		/* Serialization */
		template<class Archive>
		void serialize(Archive& archive)
		{
			archive(speed);
		}
	};
}

namespace Elixir
{
	using namespace ElixirEditor;
	using namespace ElixirGame;

	/* Draw component in editor */
	template <>
	void EditorWidget<Basket>(entt::registry& registry, entt::entity entity)
	{
	}
}
