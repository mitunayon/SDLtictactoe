#pragma once
#include "IGameSystem.h"
#include "InputProcessor.h"
#include "World.h"
#include "ImageRenderer.h"

class Game : public IInputObserver, public IWorldUpdateObserver, public IImageRendererObserver
{
private:
	InputProcessor* m_inputProcessor;
	ImageRenderer* m_imageRenderer;
	World* m_world;

public:
	Game(InputProcessor* inputProcessor, ImageRenderer* imageRenderer, World* world);

	// Inherited via IInputObserver
	virtual void OnInputUpdate(bool upPressed, bool downPressed, bool leftPressed, bool rightPressed) override;
	// Inherited via IWorldUpdateObserver
	virtual void OnWorldUpdate() override;
	// Inherited via IImageRendererObserver
	virtual void OnRenderUpdate() override;

};

