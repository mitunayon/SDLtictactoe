#include "GameTexture.h"
#include <SDL_image.h>

GameTexture::GameTexture(SDL_Renderer* renderer, std::string spritePath) :
	m_renderer(renderer)
{
	m_texture = nullptr;
	m_width = 0;
	m_height = 0;

	loadFromFile(spritePath);
}

GameTexture::~GameTexture()
{
	free();
}

bool GameTexture::loadFromFile(std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = nullptr;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == nullptr)
	{
		printf("unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0XFF));
	
		//Create texture from surface pixels
		//newTexture = IMG_LoadTexture(mRenderer, path.c_str());
		newTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
		if (newTexture == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			m_width = loadedSurface->w;
			m_height = loadedSurface->h;
		}

		// Get rif of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	m_texture = newTexture;
	return m_texture != nullptr;
}

void GameTexture::free()
{
	//Free Texture if it exists
	if (m_texture != nullptr)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = nullptr;
		m_width = 0;
		m_height = 0;
	}
}

void GameTexture::render(int x, int y)
{
	//Set renderering space and render to screen
	SDL_Rect renderQuad = { x,y, m_width, m_height };
	SDL_RenderCopy(m_renderer, m_texture, nullptr, &renderQuad);
		
}

int GameTexture::getWidth()
{
	return m_width;
}

int GameTexture::getHeight()
{
	return m_height;
}

SDL_Texture* GameTexture::getSDLTexture()
{
	return m_texture;
}

