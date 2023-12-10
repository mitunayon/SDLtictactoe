#include "GameEngine.h"
#include <chrono>
#include <cmath>

GameEngine::GameEngine() :
	m_world(new World()),
	m_inputProcessor(new InputProcessor()),
	m_imageRenderer(new ImageRenderer(m_world)),
	m_quitEngine(false)
{
	m_game = nullptr;
	m_setupController = new GameSetup();
}

int GameEngine::Run()
{
	//Main loop flag

	if (!m_setupController->SetupComplete)
	{
		m_quitEngine = true;
	}

	//While application is running
	while (!m_quitEngine)
	{
		auto startTime = std::chrono::high_resolution_clock::now();

		//Process
		m_inputProcessor->PreUpdate();
		m_inputProcessor->Update();
		m_inputProcessor->PostUpdate();

		// Simulate
		m_world->PreUpdate();
		m_world->Update();
		m_world->PostUpdate();

		//Render
		m_imageRenderer->PreUpdate();
		m_imageRenderer->Update();
		m_imageRenderer->PostUpdate();

		m_quitEngine = m_inputProcessor->IsQuitPressed();

		//Cap Framerate
		auto endTime = std::chrono::high_resolution_clock::now();
		const std::chrono::duration<double> delta = endTime - startTime;
		int msToWait = static_cast<int>(std::round(MS_PER_FRAME - delta.count()));
		SDL_Delay(msToWait);
	}

	delete m_setupController;
	delete m_inputProcessor;
	delete m_imageRenderer;
	delete m_world;

	return 0;
}

void GameEngine::Shutdown()
{
	m_quitEngine = true;
}

bool GameEngine::IsRunning()
{
	return false;
}



