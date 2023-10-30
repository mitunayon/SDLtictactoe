#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>

//Key press surfaces constants
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};

class ImageRenderer
{
private:
	bool init();
	bool close();

public:

	ImageRenderer();
	~ImageRenderer();

	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	//The window we'll be rendering to
	SDL_Window* Window = nullptr;

	SDL_Texture* LoadTexture(std::string path);

	//The window renderer
	SDL_Renderer* Renderer = nullptr;

	//The surface contained by the window
	SDL_Surface* ScreenSurface = nullptr;

	//Current displayed texture
	SDL_Texture* CurrentTexture = nullptr;

	bool LoadKeyPressImages();

	//The images that correspond to a keypress
	SDL_Texture* KeyPressTextures[KEY_PRESS_SURFACE_TOTAL];
};

