#include "TicTacToeGame.h"
#include <iostream>

TicTacToeGame::TicTacToeGame(const int players, InputProcessor* inputProcessor, ImageRenderer* imageRenderer, World* world)
: Game(inputProcessor, imageRenderer, world)
{
	// Create pieces

	// Create board

	// Create players
	m_playercount = players;
}

void TicTacToeGame::OnInputUpdate(bool upPressed, bool downPressed, bool leftPressed, bool rightPressed)
{
	Game::OnInputUpdate(upPressed, downPressed, leftPressed, rightPressed);
	std::cout << "TicTacToeGame: OnInputUpdate: " << std::endl;
}

void TicTacToeGame::OnWorldUpdate()
{
	Game::OnWorldUpdate();
	std::cout << "TicTacToeGame: OnWorldUpdate: " << std::endl;
}

void TicTacToeGame::OnRenderUpdate()
{
	Game::OnRenderUpdate();
	std::cout << "TicTacToeGame: OnRenderUpdate: " << std::endl;
}
