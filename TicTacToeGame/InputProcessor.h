#pragma once
#include <SDL.h>

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

class InputProcessor
{
public:
	SDL_Keycode CurrentInput;
	void SetCurrentInput(SDL_Keycode keycode);
	bool IsInputQueued();
	SDL_Event InputEvent;
	bool IsQuitPressed();
	bool IsInputTypeKeyDown();
};

