/*
* Created by Diego S. Seabra on 2024-01-09
*/

#include <iostream>
#include <stdio.h>

#include <SDL.h>
#undef main

// #ifdef __EMSCRIPTEN
// #include <emscripten.h>
// #endif

int main()
{
	SDL_Init(SDL_INIT_VIDEO);
	
	std::cout << "Se isso funcionar, quer dizer que foi automático pro itchio carai!!!" << std::endl;

	SDL_Quit();

	return 0;
}

