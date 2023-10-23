#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "InputProcessor.h"

class GameSetup
{

public:
	//Initialises SDL
	bool init();

	//Loads media
	bool loadMedia();

	//Frees media and shuts down SDL
	void close();

	//Loads individual image as texture
	SDL_Texture* loadTexture(std::string path);

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	//Current displayed texture
	SDL_Texture* gCurrentTexture = NULL;

	bool SetCurrentTexture(SDL_Texture* texture);

	//Select surfaces based on key press
	void ProcessInput(SDL_Keycode key);

	//The surface contained by the window
	SDL_Surface* gScreenSurface = nullptr;

	//Current displayed PNG image
	SDL_Surface* gPNGSurface = NULL;

	//The images that correspond to a keypress
	SDL_Texture* gKeyPressTextures[KEY_PRESS_SURFACE_TOTAL];

	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
};

