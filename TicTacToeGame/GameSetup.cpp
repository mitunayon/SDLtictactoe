#include "GameSetup.h"

bool GameSetup::init()
{
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		// Create window
		gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
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
					success = false;
				}
				else
				{
					gScreenSurface = SDL_GetWindowSurface(gWindow);
				}
			}
		}
	}

	return success;
}

bool GameSetup::loadMedia()
{
	bool success = true;

	//Load PNG surface
	gCurrentTexture = loadTexture("Assets/ttt-assets.png");
	if (gCurrentTexture == NULL)
	{
		printf("Failed to load texture image!\n");
		success = false;
	}

	//Load default surface
	gKeyPressTextures[KEY_PRESS_SURFACE_DEFAULT] = loadTexture("Assets/press.bmp");
	if (gKeyPressTextures[KEY_PRESS_SURFACE_DEFAULT] == NULL)
	{
		printf("Failed to load default image!\n");
		success = false;
	}

	//Load up surface
	gKeyPressTextures[KEY_PRESS_SURFACE_UP] = loadTexture("Assets/up.bmp");
	if (gKeyPressTextures[KEY_PRESS_SURFACE_UP] == NULL)
	{
		printf("Failed to load up image!\n");
		success = false;
	}

	//Load down surface
	gKeyPressTextures[KEY_PRESS_SURFACE_DOWN] = loadTexture("Assets/down.bmp");
	if (gKeyPressTextures[KEY_PRESS_SURFACE_DOWN] == NULL)
	{
		printf("Failed to load down image!\n");
		success = false;
	}

	//Load left surface
	gKeyPressTextures[KEY_PRESS_SURFACE_LEFT] = loadTexture("Assets/left.bmp");
	if (gKeyPressTextures[KEY_PRESS_SURFACE_LEFT] == NULL)
	{
		printf("Failed to load left image!\n");
		success = false;
	}

	//Load right surface
	gKeyPressTextures[KEY_PRESS_SURFACE_RIGHT] = loadTexture("Assets/right.bmp");
	if (gKeyPressTextures[KEY_PRESS_SURFACE_RIGHT] == NULL)
	{
		printf("Failed to load right image!\n");
		success = false;
	}


	return success;
}

void GameSetup::close()
{
	//Free loaded image
	SDL_DestroyTexture(gCurrentTexture);
	gCurrentTexture = NULL;

	//Destroy loaded input textures
	for (int i = 0; i < KEY_PRESS_SURFACE_TOTAL; i++)
	{
		SDL_DestroyTexture(gKeyPressTextures[i]);
	}

	//Destroy window
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

SDL_Texture* GameSetup::loadTexture(std::string path)
{
	//The final texture
	SDL_Texture* newTexture = IMG_LoadTexture(gRenderer, path.c_str());
	return newTexture;
}
