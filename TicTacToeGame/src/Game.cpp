#include "Game.h"
#include <iostream>

#include "GameObject.h"

Game::Game(InputProcessor* inputProcessor, ImageRenderer* imageRenderer, World* world) :
	m_inputProcessor(inputProcessor),
	m_imageRenderer(imageRenderer),
	m_world(world)
{
	m_inputProcessor->Attach(this);
	(*m_world).Attach(this);
	m_imageRenderer->Attach(this);

}

void Game::OnInputUpdate(bool upPressed, bool downPressed, bool leftPressed, bool rightPressed)
{
	std::cout << upPressed << downPressed << leftPressed << rightPressed << std::endl;
}

void Game::OnWorldUpdate()
{
	std::cout << "WorldUpdate:" << std::endl;

	for (auto var : *m_world->GetGameObjectsInWorld())
	{

	}


}

void Game::OnRenderUpdate()
{
	std::cout << "OnRenderUpdate" << std::endl;
}
