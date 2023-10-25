#include "ImageRenderer.h"
#include <stdio.h>

bool ImageRenderer::Init()
{
	// Create window
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	//Create renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		//Initialise renderer color
		SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			return false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
    return false;
}

bool ImageRenderer::Close()
{
	//Free loaded image
	SDL_DestroyTexture(gCurrentTexture);
	gCurrentTexture = NULL;

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	// Quit SDL Subsystems
	IMG_Quit();

	return false;
}

SDL_Texture* ImageRenderer::loadTexture(std::string path)
{
	your error is here. the gRenderer has not been created
	//The final texture
	if (gRenderer == nullptr)
	{
		printf("Error: Renderer does not exist.");
		return nullptr;
	}

	SDL_Texture* newTexture = IMG_LoadTexture(gRenderer, path.c_str());
	return newTexture;
}
