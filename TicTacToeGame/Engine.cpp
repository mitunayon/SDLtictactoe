#include "GameSetup.h"
#include "InputProcessor.h"
#include "ImageRenderer.h"
#include "World.h"
#include "TicTacToeGame.h"

int main(int argc, char* args[])
{
	GameSetup* gSetupController = new GameSetup();
	InputProcessor* gInputProcessor = new InputProcessor();
	ImageRenderer* gImageRenderer = new ImageRenderer();
	World* gWorld = new World();

	TicTacToeGame* gTicTacToeGame = new TicTacToeGame(2, gInputProcessor, gImageRenderer, gWorld);

	//Main loop flag
	bool gQuit = false;

	if (!gSetupController->SetupComplete)
	{
		gQuit = true;
	}

	//While application is running
	while (!gQuit)
	{
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
	}

	delete gSetupController;
	delete gInputProcessor;
	delete gImageRenderer;
	delete gWorld;

	return 0;
}
