#include "GameSetup.h"
#include "InputProcessor.h"
#include "ImageRenderer.h"
#include "World.h"
#include "TicTacToeGame.h"
#include <ctime>
#include <chrono>

int main(int argc, char* args[])
{
	GameSetup* gSetupController = new GameSetup();
	InputProcessor* gInputProcessor = new InputProcessor();
	ImageRenderer* gImageRenderer = new ImageRenderer();
	World* gWorld = new World();

	TicTacToeGame* gTicTacToeGame = new TicTacToeGame(2, gInputProcessor, gImageRenderer, gWorld);

	int const MAX_FPS = 60;

	//Main loop flag
	bool gQuit = false;

	if (!gSetupController->SetupComplete)
	{
		gQuit = true;
	}

	//While application is running
	while (!gQuit)
	{
		//std::time_t timeAtStartOfUpdate = std::time(nullptr);
		//const std::clock_t clockStart = std::clock();
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

		//std::time_t timeAtEndOfUpdate = std::time(nullptr);
		//const std::clock_t clockEnd = std::clock();
		//clock_t t = 1000 * (clockEnd - clockStart) /CLOCKS_PER_SEC;
		auto endTime = std::chrono::high_resolution_clock::now();
		const std::chrono::duration<double> delta = endTime - startTime;
		double f = static_cast<double>(1000) / MAX_FPS;
		double msToWait = f - delta.count();
		SDL_Delay(f);
	}

	delete gSetupController;
	delete gInputProcessor;
	delete gImageRenderer;
	delete gWorld;

	return 0;
}
