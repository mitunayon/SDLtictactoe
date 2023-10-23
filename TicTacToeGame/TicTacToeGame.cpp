#include "GameSetup.h"
#include "InputProcessor.h"
#include "ImageRenderer.h"

int main(int argc, char* args[])
{
	GameSetup* setupController = new GameSetup();
	InputProcessor inputProcessor = InputProcessor();
	ImageRenderer imageRenderer = ImageRenderer();

	if (!setupController->init())
	{
		return 1;
	}

	if (!setupController->loadMedia())
	{
		return 1;
	}

	//Main loop flag
	bool quit = false;

	//While application is running
	while (!quit)
	{
		while (inputProcessor.IsInputQueued())
		{
			if (inputProcessor.InputEvent.type == SDL_QUIT)
			{
				quit = true;
				break;
			}

			if (inputProcessor.InputEvent.type == SDL_KEYDOWN)
			{
				// what is this?
				SDL_Keycode key = inputProcessor.InputEvent.key.keysym.sym;
				inputProcessor.SetCurrentInput(key);
				//setupController->ProcessInput(key);
			}

			// Image Renderer loop
			// Set image
			switch (inputProcessor.CurrentInput)
			{
			case SDLK_UP:
				setupController->gCurrentTexture = setupController->gKeyPressTextures[KEY_PRESS_SURFACE_UP];
				break;

			case SDLK_DOWN:
				setupController->gCurrentTexture = setupController->gKeyPressTextures[KEY_PRESS_SURFACE_DOWN];
				break;

			case SDLK_LEFT:
				setupController->gCurrentTexture = setupController->gKeyPressTextures[KEY_PRESS_SURFACE_LEFT];
				break;

			case SDLK_RIGHT:
				setupController->gCurrentTexture = setupController->gKeyPressTextures[KEY_PRESS_SURFACE_RIGHT];
				break;

			default:
				setupController->gCurrentTexture = setupController->gKeyPressTextures[KEY_PRESS_SURFACE_DEFAULT];
				break;
			}

			//Clear screen
			SDL_RenderClear(setupController->gRenderer);

			//Render texture to screen
			SDL_RenderCopy(setupController->gRenderer, setupController->gCurrentTexture, NULL, NULL);

			//Update the surface
			SDL_RenderPresent(setupController->gRenderer);
		}
	}

	//Free resources and close SDL
	setupController->close();

	return 0;
}
