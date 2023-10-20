/*This source code copyrighted by Lazy Foo' Productions 2004-2023
and may not be redistributed without written permission.*/

//Using SDL, SDL_image, standard IO, and strings
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include "GameSetup.h";

int main(int argc, char* args[])
{
	GameSetup setupController;

	if (!setupController.init() && !setupController.loadMedia())
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

		//Apply the PNG image
		SDL_BlitSurface(setupController.gPNGSurface, NULL, setupController.gScreenSurface, NULL);

		//Update the surface
		SDL_UpdateWindowSurface(setupController.gWindow);
	}

	//Free resources and close SDL
	setupController.close();

	return 0;
}
