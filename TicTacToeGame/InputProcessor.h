#pragma once
#include <SDL.h>

class InputProcessor
{
public:
	InputProcessor();
	~InputProcessor();

	SDL_Keycode CurrentInput;
	void SetCurrentInput(SDL_Keycode keycode);
	bool IsInputQueued();
	SDL_Event InputEvent;
	bool IsQuitPressed();
};

