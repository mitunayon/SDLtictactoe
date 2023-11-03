#pragma once
#include "InputProcessor.h"
#include "ImageRenderer.h"
#include "World.h"

class Game
{
private:
	InputProcessor* m_inputProcessor;
	ImageRenderer* m_imageRenderer;
	World* m_world;

public:
	Game(InputProcessor* inputProcessor, ImageRenderer* imageRenderer, World* world);
};

