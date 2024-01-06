/*
*  Created by Diego S. Seabra on 2023-04-15
*/

#pragma once

#include "../../Source/Game.h"

#include <iostream>

using namespace Elixir;

namespace ElixirGame
{
	class MyGame : public Game
	{
	public:
		void RegisterComponents() override;
		void RegisterSystems() override;
		void RegisterInputActions() override;

		void SetupCamera() override;

		void Prepare() override;
		void Init() override;
		void Update() override;
		void Shutdown() override;
	};
}
