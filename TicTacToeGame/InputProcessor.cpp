#include "InputProcessor.h"

InputProcessor::InputProcessor()
{
}

InputProcessor::~InputProcessor()
{

}

void InputProcessor::SetCurrentInput(SDL_Keycode keycode)
{
	CurrentInput = keycode;
	//switch (keycode)
	//{
	//case SDLK_UP:
	//	gCurrentTexture = gKeyPressTextures[KEY_PRESS_SURFACE_UP];
	//	break;

	//case SDLK_DOWN:
	//	gCurrentTexture = gKeyPressTextures[KEY_PRESS_SURFACE_DOWN];
	//	break;

	//case SDLK_LEFT:
	//	gCurrentTexture = gKeyPressTextures[KEY_PRESS_SURFACE_LEFT];
	//	break;

	//case SDLK_RIGHT:
	//	gCurrentTexture = gKeyPressTextures[KEY_PRESS_SURFACE_RIGHT];
	//	break;

	//default:
	//	gCurrentTexture = gKeyPressTextures[KEY_PRESS_SURFACE_DEFAULT];
	//	break;
	//}
}

bool InputProcessor::IsInputQueued()
{
	return SDL_PollEvent(&InputEvent) != 0;
}

bool InputProcessor::IsQuitPressed()
{
	return InputEvent.type == SDL_QUIT;
}
