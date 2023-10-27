#include "ImageRenderer.h"
#include <stdio.h>

ImageRenderer::ImageRenderer()
{
	ImageRenderer::init();
}

ImageRenderer::~ImageRenderer()
{
	ImageRenderer::close();
}

bool ImageRenderer::init()
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

		// Load key press images
		return LoadKeyPressImages();
	}
    return false;
}

bool ImageRenderer::close()
{
	//Destroy loaded input textures
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
	{
		SDL_DestroyTexture(KeyPressTextures[i]);
	}

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

SDL_Texture* ImageRenderer::LoadTexture(std::string path)
{
	//The final texture
	if (gRenderer == nullptr)
	{
		printf("Error: Renderer does not exist.");
		return nullptr;
	}

	SDL_Texture* newTexture = IMG_LoadTexture(gRenderer, path.c_str());
	return newTexture;
}

bool ImageRenderer::LoadKeyPressImages()
{
	bool success = true;

	//Load default surface
	KeyPressTextures[KEY_PRESS_SURFACE_DEFAULT] = LoadTexture("Assets/press.bmp");
	if (KeyPressTextures[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}

	//Load up surface
	KeyPressTextures[KEY_PRESS_SURFACE_UP] = LoadTexture("Assets/up.bmp");
	if (KeyPressTextures[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("Failed to load up image!\n");
		success = false;
	}

	//Load down surface
	KeyPressTextures[KEY_PRESS_SURFACE_DOWN] = LoadTexture("Assets/down.bmp");
	if (KeyPressTextures[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		printf("Failed to load down image!\n");
		success = false;
	}

	//Load left surface
	KeyPressTextures[KEY_PRESS_SURFACE_LEFT] = LoadTexture("Assets/left.bmp");
	if (KeyPressTextures[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		printf("Failed to load left image!\n");
		success = false;
	}

	//Load right surface
	KeyPressTextures[KEY_PRESS_SURFACE_RIGHT] = LoadTexture("Assets/right.bmp");
	if (KeyPressTextures[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		printf("Failed to load right image!\n");
		success = false;
	}
	return success;
}
