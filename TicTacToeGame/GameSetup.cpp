#include "GameSetup.h"
#include "ImageRenderer.h"

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

bool GameSetup::loadMedia(ImageRenderer* renderer)
{
	bool success = true;

	////Load PNG surface
	//gCurrentTexture = loadTexture("Assets/ttt-assets.png");
	//if (gCurrentTexture == NULL)
	//{
	//	printf("Failed to load texture image!\n");
	//	success = false;
	//}

	//Load default surface
	gKeyPressTextures[KEY_PRESS_SURFACE_DEFAULT] = renderer->loadTexture("Assets/press.bmp");
	if (gKeyPressTextures[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}

	//Load up surface
	gKeyPressTextures[KEY_PRESS_SURFACE_UP] = renderer->loadTexture("Assets/up.bmp");
	if (gKeyPressTextures[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("Failed to load up image!\n");
		success = false;
	}

	//Load down surface
	gKeyPressTextures[KEY_PRESS_SURFACE_DOWN] = renderer->loadTexture("Assets/down.bmp");
	if (gKeyPressTextures[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		printf("Failed to load down image!\n");
		success = false;
	}

	//Load left surface
	gKeyPressTextures[KEY_PRESS_SURFACE_LEFT] = renderer->loadTexture("Assets/left.bmp");
	if (gKeyPressTextures[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		printf("Failed to load left image!\n");
		success = false;
	}

	//Load right surface
	gKeyPressTextures[KEY_PRESS_SURFACE_RIGHT] = renderer->loadTexture("Assets/right.bmp");
	if (gKeyPressTextures[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		printf("Failed to load right image!\n");
		success = false;
	}


	return success;
}

void GameSetup::close()
{
	//Destroy loaded input textures
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
	{
		SDL_DestroyTexture(gKeyPressTextures[i]);
	}

	//Quit SDL subsystems
	SDL_Quit();
}


