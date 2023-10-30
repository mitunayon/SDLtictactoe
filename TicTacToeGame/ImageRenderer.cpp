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
	Window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (Window == NULL)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	//Create renderer for window
	Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED);
	if (Renderer == NULL)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		//Initialise renderer color
		SDL_SetRenderDrawColor(Renderer, 0xFF, 0xFF, 0xFF, 0xFF);

		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			return false;
		}
		else
		{
			ScreenSurface = SDL_GetWindowSurface(Window);
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
	SDL_DestroyTexture(CurrentTexture);
	CurrentTexture = NULL;

	//Destroy window
	SDL_DestroyRenderer(Renderer);
	SDL_DestroyWindow(Window);
	Window = NULL;
	Renderer = NULL;

	// Quit SDL Subsystems
	IMG_Quit();

	return false;
}

SDL_Texture* ImageRenderer::LoadTexture(std::string path)
{
	//The final texture
	if (Renderer == nullptr)
	{
		printf("Error: Renderer does not exist.");
		return nullptr;
	}

	SDL_Texture* newTexture = IMG_LoadTexture(Renderer, path.c_str());
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