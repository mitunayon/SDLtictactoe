#include "GameSetup.h"

int main(int argc, char* args[])
{
	GameSetup setupController;

	if (!setupController.init())
	{
		return 1;
	}

	if (!setupController.loadMedia())
	{
		return 1;
	}

	//Main loop flag
	bool quit = false;

	//Event handler
	SDL_Event e;

	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		//Clear screen
		SDL_RenderClear(setupController.gRenderer);

		//Render texture to screen
		SDL_RenderCopy(setupController.gRenderer, setupController.gTexture, NULL, NULL);

		//Update the surface
		SDL_RenderPresent(setupController.gRenderer);
	}

	//Free resources and close SDL
	setupController.close();

	return 0;
}
