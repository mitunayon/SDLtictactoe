#include "ImageRenderer.h"
#include <stdio.h>
#include <GameTexture.h>

ImageRenderer::ImageRenderer()
{
	ImageRenderer::init();
}

ImageRenderer::~ImageRenderer()
{
	ImageRenderer::close();
}

// Private
bool ImageRenderer::init()
{
	// Create window
	m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (m_window == nullptr)
	{
		printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	//Create renderer for window
	m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
	if (m_renderer == nullptr)
	{
		printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
		return false;
	}
	else
	{
		//Initialise renderer color
		SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);

		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
			return false;
		}
		else
		{
			m_screenSurface = SDL_GetWindowSurface(m_window);
		}

		//loading test textures
		bgTexture = new GameTexture(m_renderer);
		bgTexture->loadFromFile("Assets/background.png");

		fooTexture = new GameTexture(m_renderer);
		fooTexture->loadFromFile("Assets/foo.png");

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
	SDL_DestroyTexture(m_currentTexture);
	m_currentTexture = nullptr;

	//Free loaded images
	fooTexture->free();
	bgTexture->free();

	//Destroy window
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	m_window = nullptr;
	m_renderer = nullptr;

	// Quit SDL Subsystems
	IMG_Quit();

	return false;
}

// Public
void ImageRenderer::Update()
{
	Notify();

	//Clear screen
	SDL_SetRenderDrawColor(m_renderer, 128, 128, 128, 0xFF);
	SDL_RenderClear(m_renderer);

	//Scene Textures
	//background
	bgTexture->render(0, 0);

	//foreground
	fooTexture->render(240, 190);

	//Render texture to screen
	std::list<IRenderable*>::iterator iterator = m_renderables.begin();
	while (iterator != m_renderables.end())
	{
		// Render this Gameobject (IRenderable) to the position it is in.
		//iterator->
		fooTexture->render(240, 190);

		//SDL_RenderCopy(m_renderer, m_currentTexture, nullptr, nullptr);
		++iterator;
	}

	//Update the surface
	SDL_RenderPresent(m_renderer);

}

void ImageRenderer::PreUpdate()
{
}

void ImageRenderer::PostUpdate()
{
}

SDL_Texture* ImageRenderer::LoadTexture(std::string path)
{
	//The final texture
	if (m_renderer == nullptr)
	{
		printf("Error: Renderer does not exist.");
		return nullptr;
	}

	SDL_Texture* newTexture = IMG_LoadTexture(m_renderer, path.c_str());
	return newTexture;
}

bool ImageRenderer::LoadKeyPressImages()
{
	bool success = true;

	//Load default surface
	KeyPressTextures[KEY_PRESS_SURFACE_DEFAULT] = LoadTexture("Assets/press.bmp");
	if (KeyPressTextures[KEY_PRESS_SURFACE_DEFAULT] == nullptr)
	{
		printf("Failed to load default image!\n");
		success = false;
	}

	//Load up surface
	KeyPressTextures[KEY_PRESS_SURFACE_UP] = LoadTexture("Assets/up.bmp");
	if (KeyPressTextures[KEY_PRESS_SURFACE_UP] == nullptr)
	{
		printf("Failed to load up image!\n");
		success = false;
	}

	//Load down surface
	KeyPressTextures[KEY_PRESS_SURFACE_DOWN] = LoadTexture("Assets/down.bmp");
	if (KeyPressTextures[KEY_PRESS_SURFACE_DOWN] == nullptr)
	{
		printf("Failed to load down image!\n");
		success = false;
	}

	//Load left surface
	KeyPressTextures[KEY_PRESS_SURFACE_LEFT] = LoadTexture("Assets/left.bmp");
	if (KeyPressTextures[KEY_PRESS_SURFACE_LEFT] == nullptr)
	{
		printf("Failed to load left image!\n");
		success = false;
	}

	//Load right surface
	KeyPressTextures[KEY_PRESS_SURFACE_RIGHT] = LoadTexture("Assets/right.bmp");
	if (KeyPressTextures[KEY_PRESS_SURFACE_RIGHT] == nullptr)
	{
		printf("Failed to load right image!\n");
		success = false;
	}
	return success;
}

void ImageRenderer::Attach(IImageRendererObserver* observer)
{
	m_observers.push_back(observer);
}

void ImageRenderer::Detach(IImageRendererObserver* observer)
{
	m_observers.remove(observer);
}

void ImageRenderer::Notify()
{
	std::list<IImageRendererObserver*>::iterator iterator = m_observers.begin();
	while (iterator != m_observers.end())
	{
		(*iterator)->OnRenderUpdate();
		++iterator;
	}
}

void ImageRenderer::AddRenderable(IRenderable* renderable)
{
	m_renderables.push_back(renderable);
}

