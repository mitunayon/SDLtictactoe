#include "Game.h"

Game::Game(InputProcessor* inputProcessor, ImageRenderer* imageRenderer, World* world)
{
	m_inputProcessor = inputProcessor;
	m_imageRenderer = imageRenderer;
	m_world = world;
}
