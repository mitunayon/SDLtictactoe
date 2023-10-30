#include "GameSetup.h"
#include "InputProcessor.h"
#include "ImageRenderer.h"

int main(int argc, char* args[])
{
	GameSetup* gSetupController = new GameSetup();
	InputProcessor gInputProcessor = InputProcessor();
	ImageRenderer* gImageRenderer = new ImageRenderer();

	if (!gSetupController->init())
	{
		return 1;
	}

	//Main loop flag
	bool gQuit = false;

	//While application is running
	while (!gQuit)
	{
		while (gInputProcessor.IsInputQueued())
		{
			if (gInputProcessor.InputEvent.type == SDL_QUIT)
			{
				gQuit = true;
				break;
			}

			if (gInputProcessor.InputEvent.type == SDL_KEYDOWN)
			{
				// what is this?
				SDL_Keycode key = gInputProcessor.InputEvent.key.keysym.sym;
				gInputProcessor.SetCurrentInput(key);
				//setupController->ProcessInput(key);
			}

			// Image Renderer loop
			// Set image
			switch (gInputProcessor.CurrentInput)
			{
			case SDLK_UP:
				gImageRenderer->CurrentTexture = gImageRenderer->KeyPressTextures[KEY_PRESS_SURFACE_UP];
				break;

			case SDLK_DOWN:
				gImageRenderer->CurrentTexture = gImageRenderer->KeyPressTextures[KEY_PRESS_SURFACE_DOWN];
				break;

			case SDLK_LEFT:
				gImageRenderer->CurrentTexture = gImageRenderer->KeyPressTextures[KEY_PRESS_SURFACE_LEFT];
				break;

			case SDLK_RIGHT:
				gImageRenderer->CurrentTexture = gImageRenderer->KeyPressTextures[KEY_PRESS_SURFACE_RIGHT];
				break;

			default:
				gImageRenderer->CurrentTexture = gImageRenderer->KeyPressTextures[KEY_PRESS_SURFACE_DEFAULT];
				break;
			}
		}


		//Clear screen
		SDL_RenderClear(gImageRenderer->Renderer);

		//Render texture to screen
		SDL_RenderCopy(gImageRenderer->Renderer, gImageRenderer->CurrentTexture, NULL, NULL);

		//Update the surface
		SDL_RenderPresent(gImageRenderer->Renderer);

	}

	//Free resources and close SDL
	gSetupController->close();

	return 0;
}
