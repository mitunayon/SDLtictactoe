#include "GameSetup.h"
#include <SDL.h>
#include <stdio.h>

GameSetup::~GameSetup()
{
	close();
}

bool GameSetup::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	return success;
}

void GameSetup::close()
{
	//Quit SDL subsystems
	SDL_Quit();
}


