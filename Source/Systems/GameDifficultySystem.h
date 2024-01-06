/*
* Created by Diego S. Seabra on 2024-01-06
*/

#pragma once

#include <iostream>

namespace ElixirGame
{
	struct GameDifficultySystem
	{
	public:

		inline static uint32_t GetLevel()
		{
			return currentLevel;
		}

		inline static void Increase()
		{
			// TODO: Which is the maximum level we can get?
			currentLevel++;
		}

		inline static void Decrease()
		{
			if (currentLevel > 0)
				currentLevel--;
		}

	private:

		inline static uint32_t currentLevel = 1;

	};
}
