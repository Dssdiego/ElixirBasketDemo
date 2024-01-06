/*
* Created by Diego S. Seabra on 2023-04-15
*/

#include "MyGame.h"
#include "BasketGame.h"

#include <imgui/IconsMaterialDesignIcons.h>

#include "../Source/Logging/Logger.h"
#include "../Source/Color/Color.h"

#include "../Source/ECS/EntityEditor.h"
#include "../Source/ECS/SystemEditor.h"

#include "../Source/Rendering/Camera.h"

#include "../Source/Input/Mouse.h"
#include "../Source/Input/Keyboard.h"

#include "Components/Ball.h"
#include "Components/Basket.h"
#include "Components/ThrowLineLimit.h"

#include "Archetypes/BallArchetype.h"

#include "Systems/BallDestructionSystem.h"
#include "Systems/BallCollisionSystem.h"
#include "Systems/BallSpawnSystem.h"
#include "Systems/BasketMovementSystem.h"

using namespace ElixirGame;

void MyGame::RegisterComponents()
{
	Logger::Info(ELogContext::GAME, "Registering game components...");

	// components
	EntityEditor::RegisterComponent<Ball>(ICON_MDI_BASKETBALL, "game");
	EntityEditor::RegisterComponent<Basket>(ICON_MDI_BASKETBALL_HOOP, "game");
	EntityEditor::RegisterComponent<ThrowLineLimit>(ICON_MDI_BASKETBALL_HOOP, "game");
}

void MyGame::RegisterSystems()
{
	Logger::Info(ELogContext::GAME, "Registering game systems...");

	SystemEditor::RegisterSystem<BallDestructionSystem>(ICON_MDI_BASKETBALL);
	SystemEditor::RegisterSystem<BallCollisionSystem>(ICON_MDI_BASKETBALL);
	SystemEditor::RegisterSystem<BallSpawnSystem>(ICON_MDI_BASKETBALL);

	SystemEditor::RegisterSystem<BasketMovementSystem>(ICON_MDI_BASKETBALL);
}

void MyGame::RegisterInputActions()
{	
	//Input::CreateInputActionsFromFile("configs/gameInputActions.yaml");
}

void MyGame::SetupCamera()
{
	Camera::SetOrtographicZoom(0.5f);
	Camera::SetWorldPosition(glm::vec3(0.f, 0.f, 0.f));
}

void MyGame::Prepare()
{
	SetTitle("Basket Game");
}

void MyGame::Init()
{
	Logger::Info(ELogContext::GAME, "My game init");

	//Window::EnableVSync(false);
	//Window::SetMode(EWindowMode::BORDERLESS_FULLSCREEN); 
	//Window::EnableWindowResizing(false);
	//Window::Resize(480, 600);

	Color::EngineClear = Color::GMB_4;

	BasketGame::CreateWorld();

	//Time::SetScale(0.1f);
}

void MyGame::Update()
{
	// Mouse Tests
	/*if (Mouse::IsScrollingDown())
	{
		Logger::Debug(ELogContext::INPUT, "Scrolling down");
	}

	if (Mouse::IsButtonPressed(EMouseButton::BUTTON_LEFT))
	{
		Logger::Debug(ELogContext::INPUT, "Click mouse left");
	}

	if (Mouse::IsButtonReleased(EMouseButton::BUTTON_LEFT))
	{
		Logger::Debug(ELogContext::INPUT, "Released mouse left");
	}

	if (Mouse::IsButtonPressed(EMouseButton::BUTTON_MIDDLE))
	{
		Logger::Debug(ELogContext::INPUT, "Click mouse middle");
	}

	if (Mouse::IsButtonPressed(EMouseButton::BUTTON_RIGHT))
	{
		Logger::Debug(ELogContext::INPUT, "Click mouse right");
	}

	if (Mouse::IsButtonHold(EMouseButton::BUTTON_MIDDLE))
	{
		Logger::Debug(ELogContext::INPUT, "Hold middle mouse finger :P");
	}*/
}

void MyGame::Shutdown()
{
	Logger::Info(ELogContext::GAME, "My game shutdown");
}

