/*
* Created by Diego S. Seabra on 2023-08-31
*/

#pragma once

#include "../Source/ECS/EntityEditor.h"
#include "../Source/Editor/EditorDraw.h"

#include "../Source/Color/Color.h"

namespace ElixirGame
{
	struct DVD
	{
		glm::vec3 direction = glm::vec3(1.f, 1.f, 0.f);
		Color lastColor = Color::White;
		float speed = 0.5f;

		/* Serialization */
		template<class Archive>
		void serialize(Archive& archive)
		{
			archive(direction.x, direction.y, direction.z);
			archive(lastColor.r, lastColor.g, lastColor.b, lastColor.a);
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
	void EditorWidget<DVD>(entt::registry& registry, entt::entity entity)
	{
		DVD& dvdLogo = registry.get<DVD>(entity);

		EditorDraw::Vec3Control("Direction", dvdLogo.direction);
		ImGui::SliderFloat("Speed", &dvdLogo.speed, 0.f, 10.f);
	}
}
