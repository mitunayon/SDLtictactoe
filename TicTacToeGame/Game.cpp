#include "Game.h"
#include <iostream>

Game::Game(InputProcessor* inputProcessor, ImageRenderer* imageRenderer, World* world)
{
	m_inputProcessor = inputProcessor;
	m_imageRenderer = imageRenderer;
	m_world = world;

	m_inputProcessor->Attach(this);
	(*m_world).Attach(this);

}

void Game::Update()
{
}

void Game::PreUpdate()
{
}

void Game::PostUpdate()
{
}

void Game::OnInputUpdate(bool upPressed, bool downPressed, bool leftPressed, bool rightPressed)
{
	std::cout << upPressed << downPressed << leftPressed << rightPressed << std::endl;
}

void Game::OnWorldUpdate()
{
}
