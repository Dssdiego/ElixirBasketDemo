/*
* Created by Diego S. Seabra on 2023-12-26
*/

#pragma once

#include "../Source/ECS/Components/WorldTransform.h"
#include "../Source/ECS/Components/Sprite.h"

#include "../Source/Structures/Array.h"
#include "../Source/Color/Color.h"

#include "../Source/ECS/SystemEditor.h"

#include "../Source/Math/RandomGenerator.h"

#include "../Components/DVD.h"

namespace ElixirGame
{
	using namespace Elixir;

	struct LogoCollisionSystem
	{
	public:
		inline static Array<Color> PossibleColors = {};
	};
}

namespace Elixir
{
	using namespace ElixirGame;

	template <>
	void SystemInit<LogoCollisionSystem>()
	{
		// What colors the logo can have?
		LogoCollisionSystem::PossibleColors.Add(Color::Purple);
		LogoCollisionSystem::PossibleColors.Add(Color::Red);
		LogoCollisionSystem::PossibleColors.Add(Color::Green);
		LogoCollisionSystem::PossibleColors.Add(Color::Blue);
		LogoCollisionSystem::PossibleColors.Add(Color::Yellow);
		LogoCollisionSystem::PossibleColors.Add(Color::Purple);
		LogoCollisionSystem::PossibleColors.Add(Color::Cyan);
		LogoCollisionSystem::PossibleColors.Add(Color::Pink);
		LogoCollisionSystem::PossibleColors.Add(Color::White);
	}

	template <>
	void SystemUpdate<LogoCollisionSystem>(entt::registry& registry)
	{
		// deal a card
		auto view = registry.view<DVD>();

		for (auto entity : view)
		{
			auto collided = false;

			if (!registry.valid(entity))
				return;

			DVD& dvdLogo = registry.get<DVD>(entity);
			Sprite& sprite = registry.get<Sprite>(entity);

			WorldTransform& worldTransform = registry.get<WorldTransform>(entity);
			
			// HORIZONTAL MOVEMENT
			if (worldTransform.position.x > 3.f && worldTransform.position.x < 3.05f)
			{
				collided = true;
				dvdLogo.direction.x *= -1.f;
			}

			else if (worldTransform.position.x < -3.f && worldTransform.position.x > -3.05f)
			{
				collided = true;
				dvdLogo.direction.x *= -1.f;
			}

			// VERTICAL MOVEMENT
			else if (worldTransform.position.y > 1.6f && worldTransform.position.y < 1.65f)
			{
				collided = true;
				dvdLogo.direction.y *= -1.f;
			}

			else if (worldTransform.position.y < -1.3f && worldTransform.position.y > -1.35f)
			{
				collided = true;
				dvdLogo.direction.y *= -1.f;
			}

			// COLLISION - CHANGE COLOR
			if (collided)
			{
				//while (dvdLogo.lastColor.r == sprite.color.r &&
				//	dvdLogo.lastColor.g == sprite.color.g &&
				//	dvdLogo.lastColor.b == sprite.color.b &&
				//	dvdLogo.lastColor.a == sprite.color.a
				//	)
				//{
				//}
				sprite.color = LogoCollisionSystem::PossibleColors[RandomGenerator::RandomInt(1, LogoCollisionSystem::PossibleColors.Size() - 1)];
				dvdLogo.lastColor = sprite.color;
				break;
			}
		}
	}
}

