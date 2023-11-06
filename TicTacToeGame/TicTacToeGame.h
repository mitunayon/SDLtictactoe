#pragma once
#include "Game.h"
#include "InputProcessor.h"
#include "ImageRenderer.h"
#include "World.h"

class TicTacToeGame : public Game
{
private:
	int m_playercount = 0;

public:
	TicTacToeGame(const int players, InputProcessor* inputProcessor, ImageRenderer* imageRenderer, World* world);

	virtual void OnInputUpdate(bool upPressed, bool downPressed, bool leftPressed, bool rightPressed) override;
	virtual void OnWorldUpdate() override;
	virtual void OnRenderUpdate() override;
};

