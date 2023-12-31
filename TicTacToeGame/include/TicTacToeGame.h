#pragma once
#include "Game.h"

class GameObject;

class TicTacToeGame : public Game
{
private:
	int m_playercount = 0;

	GameObject* m_player;
	GameObject* m_board;

public:
	TicTacToeGame(const int players, InputProcessor* inputProcessor, ImageRenderer* imageRenderer, World* world);

	virtual void OnInputUpdate(bool upPressed, bool downPressed, bool leftPressed, bool rightPressed) override;
	virtual void OnWorldUpdate() override;
	virtual void OnRenderUpdate() override;
};

