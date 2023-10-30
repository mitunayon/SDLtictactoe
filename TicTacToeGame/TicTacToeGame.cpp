#include "GameSetup.h"
#include "InputProcessor.h"
#include "ImageRenderer.h"

int main(int argc, char* args[])
{
	GameSetup* gSetupController = new GameSetup();
	InputProcessor* gInputProcessor = new InputProcessor();
	ImageRenderer* gImageRenderer = new ImageRenderer();

	//Main loop flag
	bool gQuit = false;

	if (!gSetupController->SetupComplete)
	{
		gQuit = true;
	}

	//While application is running
	while (!gQuit)
	{
		gInputProcessor->Update();
		gQuit = gInputProcessor->IsQuitPressed();

		gImageRenderer->Update();
	}

	delete gSetupController;
	delete gInputProcessor;
	delete gImageRenderer;

	return 0;
}
