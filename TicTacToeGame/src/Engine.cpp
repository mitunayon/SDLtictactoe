#include "GameSetup.h"
#include "InputProcessor.h"
#include "ImageRenderer.h"
#include "World.h"
#include "TicTacToeGame.h"
#include <chrono>
#include <cmath>

int main(int argc, char* args[])
{
	World* gWorld = new World();
	GameSetup* gSetupController = new GameSetup();
	InputProcessor* gInputProcessor = new InputProcessor();
	ImageRenderer* gImageRenderer = new ImageRenderer(gWorld);

	TicTacToeGame* gTicTacToeGame = new TicTacToeGame(2, gInputProcessor, gImageRenderer, gWorld);

	int const MAX_FPS = 30;
	double const MS_PER_FRAME = static_cast<double>(1000) / MAX_FPS;

	//Main loop flag
	bool gQuit = false;

	if (!gSetupController->SetupComplete)
	{
		gQuit = true;
	}

	//While application is running
	while (!gQuit)
	{
		auto startTime = std::chrono::high_resolution_clock::now();

		//Process
		gInputProcessor->PreUpdate();
		gInputProcessor->Update();
		gInputProcessor->PostUpdate();

		// Simulate
		gWorld->PreUpdate();
		gWorld->Update();
		gWorld->PostUpdate();

		//Render
		gImageRenderer->PreUpdate();
		gImageRenderer->Update();
		gImageRenderer->PostUpdate();
		
		gQuit = gInputProcessor->IsQuitPressed();

		//Cap Framerate
		auto endTime = std::chrono::high_resolution_clock::now();
		const std::chrono::duration<double> delta = endTime - startTime;
		int msToWait = static_cast<int>(std::round(MS_PER_FRAME - delta.count()));
		SDL_Delay(msToWait);
	}

	delete gSetupController;
	delete gInputProcessor;
	delete gImageRenderer;
	delete gWorld;

	return 0;
}


