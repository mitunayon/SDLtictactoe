#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "IGameSystem.h"

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

class ImageRenderer : public IGameSystem
{
private:
	bool init();
	bool close();

	//The window renderer
	SDL_Renderer* m_renderer = nullptr;

	//The window we'll be rendering to
	SDL_Window* m_window = nullptr;

	//The surface contained by the window
	SDL_Surface* m_screenSurface = nullptr;

	//Current displayed texture
	SDL_Texture* m_currentTexture = nullptr;

public:

	ImageRenderer();
	~ImageRenderer();

	// Inherited via IGameSystem
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void PostUpdate() override;

	//Screen dimension constants
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Texture* LoadTexture(std::string path);
	bool LoadKeyPressImages();

	//The images that correspond to a keypress
	SDL_Texture* KeyPressTextures[KEY_PRESS_SURFACE_TOTAL];
};

