#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

class GameSetup
{

public:
	//Initialises SDL
	bool init();

	//Loads media
	bool loadMedia();

	//Frees media and shuts down SDL
	void close();

	//Loads individual image
	SDL_Surface* loadSurface(std::string path);

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The surface contained by the window
	SDL_Surface* gScreenSurface = nullptr;

	//Current displayed PNG image
	SDL_Surface* gPNGSurface = NULL;

	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
};

