#pragma once
#include <string>
#include <SDL.h>

// Texture wrapper class
class GameTexture
{
public:
	GameTexture(SDL_Renderer* renderer);
	~GameTexture();

	bool loadFromFile(std::string path);

	//deallocate texture
	void free();

	//Renders texture at given point
	void render(int x, int y);

	//Gets image dimensions
	int getWidth();
	int getHeight();

private:
	SDL_Renderer* mRenderer;

	//the actual hardware texture
	SDL_Texture* mTexture;

	//Image dimensions
	int mWidth;
	int mHeight;
};

