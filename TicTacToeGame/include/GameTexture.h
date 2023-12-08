#pragma once
#include <string>
#include <SDL.h>

// Texture wrapper class
class GameTexture
{
public:
	GameTexture(SDL_Renderer* renderer, std::string spritePath);
	~GameTexture();

	bool loadFromFile(std::string path);

	//deallocate texture
	void free();

	//Renders texture at given point
	void render(int x, int y);

	//Gets image dimensions
	int getWidth();
	int getHeight();

	SDL_Texture* getSDLTexture();

private:
	SDL_Renderer* const m_renderer;

	//the actual hardware texture
	SDL_Texture* m_texture;

	//Image dimensions
	int m_width;
	int m_height;
};

