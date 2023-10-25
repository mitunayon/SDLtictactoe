#pragma once
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "InputProcessor.h"
#include "ImageRenderer.h"

class GameSetup
{

public:
	//Initialises SDL
	bool init();

	//Loads media
	bool loadMedia(ImageRenderer* renderer);

	//Frees media and shuts down SDL
	void close();

	//Current displayed PNG image
	SDL_Surface* gPNGSurface = NULL;

	//The images that correspond to a keypress
	SDL_Texture* gKeyPressTextures[KEY_PRESS_SURFACE_TOTAL];

};

