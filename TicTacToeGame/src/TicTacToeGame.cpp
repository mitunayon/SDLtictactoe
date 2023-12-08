#include "TicTacToeGame.h"
#include <iostream>

TicTacToeGame::TicTacToeGame(const int players, InputProcessor* inputProcessor, ImageRenderer* imageRenderer, World* world)
: Game(inputProcessor, imageRenderer, world)
{
	// Create pieces
	m_player = CreateGameObject<BoardGameObject>("Assets/foo.png");

	// Create board
	m_board = CreateGameObject<BoardGameObject>("Assets/background.png");

	// Create players
	m_playercount = players;
}

void TicTacToeGame::OnInputUpdate(bool upPressed, bool downPressed, bool leftPressed, bool rightPressed)
{
	Game::OnInputUpdate(upPressed, downPressed, leftPressed, rightPressed);
	std::cout << "TicTacToeGame: OnInputUpdate: " << std::endl;

	if (upPressed)
	{
		m_player->Move(0,5);
	}

	if (downPressed) 
	{
		m_player->Move(0,- 5);
	}

	if (leftPressed)
	{
		m_player->Move(-5, 0);
	}

	if (rightPressed)
	{
		m_player->Move(5, 0);
	}
}

void TicTacToeGame::OnWorldUpdate()
{
	Game::OnWorldUpdate();
	std::cout << "TicTacToeGame: OnWorldUpdate: X" << m_player->GetPosition().X << ",Y" << m_player->GetPosition().Y << std::endl;
}

void TicTacToeGame::OnRenderUpdate()
{
	Game::OnRenderUpdate();
	std::cout << "TicTacToeGame: OnRenderUpdate: " << std::endl;
}
