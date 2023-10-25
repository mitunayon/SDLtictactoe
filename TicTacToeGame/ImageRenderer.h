#pragma once
//#include <SDL.h>
#include <SDL_image.h>
#include <string>

class ImageRenderer
{
public:

	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	
	bool Render();

	bool Init();

	bool Close();

	SDL_Texture* loadTexture(std::string path);

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	//The surface contained by the window
	SDL_Surface* gScreenSurface = nullptr;

	//Current displayed texture
	SDL_Texture* gCurrentTexture = NULL;
};

