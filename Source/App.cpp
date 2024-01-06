/*
* Created by Diego S. Seabra on 2023-02-14
*/

#include <iostream>
#ifdef _WIN32
#include <Windows.h>
#endif

#include "../Source/Elixir.h"
#include "../Source/Logging/Logger.h"
#include "MyGame.h"

#include <chrono>

using namespace Elixir;
using namespace ElixirGame;

int main()
{
	Engine engine;
	MyGame game;

	//EngineConfig config{
	//		"Alchymia Solitaire",
	//		{Config::GetWindowWidth(), Config::GetWindowHeight()},
	//		{320, 240},
	//		Config::GetSaveToLogFile() // FIXME: Logger saves automatically so this config is useless right now!
	//};
	try 
	{
		std::chrono::steady_clock::time_point beginTimePoint = std::chrono::steady_clock::now();
		engine.Init(&game);
		std::chrono::steady_clock::time_point endTimePoint = std::chrono::steady_clock::now();
		
		auto msToStart = std::chrono::duration_cast<std::chrono::milliseconds>(endTimePoint - beginTimePoint).count();

		Logger::Info(ELogContext::CORE, "The engine took " + std::to_string(msToStart) + " ms to start");

		engine.Run();
		engine.Shutdown();
	}
	catch (const std::exception& e) 
	{
		Logger::Error(ELogContext::EXCEPTION, e.what(), "");
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

#ifdef _WIN32
int CALLBACK WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	return main();
}
#endif // _WIN32
