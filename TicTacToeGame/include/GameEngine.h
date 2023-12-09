#pragma once
#include "GameSetup.h"
#include "InputProcessor.h"
#include "ImageRenderer.h"
#include "World.h"
#include "Game.h"

class GameEngine
{
private:

	World* m_world;
	GameSetup* m_setupController;
	Game* m_game;

	InputProcessor* const m_inputProcessor;
	ImageRenderer* const m_imageRenderer;

	int const MAX_FPS = 30;
	double const MS_PER_FRAME = static_cast<double>(1000) / MAX_FPS;

public:

	GameEngine();
	int Run();

	template<typename T>
	T* InitGame() 
	{
		static_assert(std::is_base_of_v<Game, T>);

		int playerCount = 2;
		T* game = new T(playerCount, m_inputProcessor, m_imageRenderer, m_world);
		m_game = game;
		return game;
	}
};