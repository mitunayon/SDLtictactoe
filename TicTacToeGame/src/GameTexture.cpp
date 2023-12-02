#include "GameTexture.h"
#include <SDL_image.h>

GameTexture::GameTexture(SDL_Renderer* renderer)
{
	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;

	mRenderer = renderer;
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
		newTexture = SDL_CreateTextureFromSurface(mRenderer, loadedSurface);
		if (newTexture == nullptr)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}

		// Get rif of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != nullptr;
}

void GameTexture::free()
{
	//Free Texture if it exists
	if (mTexture != nullptr)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = nullptr;
		mWidth = 0;
		mHeight = 0;
	}
}

void GameTexture::render(int x, int y)
{
	//Set renderering space and render to screen
	SDL_Rect renderQuad = { x,y, mWidth, mHeight };
	SDL_RenderCopy(mRenderer, mTexture, nullptr, &renderQuad);
		
}

int GameTexture::getWidth()
{
	return mWidth;
}

int GameTexture::getHeight()
{
	return mHeight;
}

