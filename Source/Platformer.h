/*
* Created by Diego S. Seabra on 2023-10-26
*/

#pragma once

#include "Editor/GameEditor.h"

#include <glm/glm.hpp>

namespace ElixirGame
{
	using namespace ElixirGameEditor;

	class Platformer
	{
		friend class GameEditor;

	public:
		static void CreateWorld();
	};
}
