#include "GameSetup.h"
#include "InputProcessor.h"
#include "ImageRenderer.h"
#include "GameObjectRegistry.h"

int main(int argc, char* args[])
{
	GameSetup* gSetupController = new GameSetup();
	InputProcessor* gInputProcessor = new InputProcessor();
	ImageRenderer* gImageRenderer = new ImageRenderer();
	GameObjectRegistry* gGameObjectRegistry = new GameObjectRegistry();

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

		gGameObjectRegistry->PreUpdate();
		gGameObjectRegistry->Update();
		gGameObjectRegistry->PostUpdate();

		gImageRenderer->Update();
	}

	delete gSetupController;
	delete gInputProcessor;
	delete gImageRenderer;
	delete gGameObjectRegistry;

	return 0;
}
