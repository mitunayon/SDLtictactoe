#pragma once
#include "IGameSystem.h"
#include "InputProcessor.h"
#include "World.h"
#include "ImageRenderer.h"

class Game : public IGameSystem, public IInputObserver, public IWorldUpdateObserver, public IImageRendererObserver
{
private:
	InputProcessor* m_inputProcessor;
	ImageRenderer* m_imageRenderer;
	World* m_world;

public:
	Game(InputProcessor* inputProcessor, ImageRenderer* imageRenderer, World* world);

	// Inherited via IGameSystem
	virtual void Update() = 0;
	virtual void PreUpdate() = 0;
	virtual void PostUpdate() = 0;

	// Inherited via IInputObserver
	void OnInputUpdate(bool upPressed, bool downPressed, bool leftPressed, bool rightPressed) override;


	// Inherited via IWorldUpdateObserver
	void OnWorldUpdate() override;


	// Inherited via IImageRendererObserver
	void OnRenderUpdate() override;

};

