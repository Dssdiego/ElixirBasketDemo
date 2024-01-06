/*
* Created by Diego S. Seabra on 2023-12-26
*/

#pragma once

#include "Editor/GameEditor.h"

#include "../Source/Structures/Array.h"

#include <glm/glm.hpp>
#include <vector>

namespace ElixirGame
{
	using namespace Elixir;
	using namespace ElixirGameEditor;

	class DVDLogo
	{
		friend class GameEditor;

	public:
		static void CreateWorld();

		inline static glm::vec3 LogoScale = { 1.f, 0.6f, 0.f };
	};
}
