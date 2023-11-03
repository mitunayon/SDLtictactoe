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
		//Process
		gInputProcessor->PreUpdate();
		gInputProcessor->Update();
		gInputProcessor->PostUpdate();

		// Simulate
		gGameObjectRegistry->PreUpdate();
		gGameObjectRegistry->Update();
		gGameObjectRegistry->PostUpdate();

		//Render
		gImageRenderer->PreUpdate();
		gImageRenderer->Update();
		gImageRenderer->PostUpdate();
		
		gQuit = gInputProcessor->IsQuitPressed();
	}

	delete gSetupController;
	delete gInputProcessor;
	delete gImageRenderer;
	delete gGameObjectRegistry;

	return 0;
}
