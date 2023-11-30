#pragma once
#include "IGameSystem.h"
#include "InputProcessor.h"
#include "World.h"
#include "ImageRenderer.h"
#include "GameObject.h"
#include "IRenderable.h"

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

	template <typename T>
	T* CreateGameObject()
	{
		static_assert(std::is_base_of_v<GameObject, T>);

		T* gameObject = new T(0, 0);

		m_world->AddGameObject(gameObject);
		m_imageRenderer->AddRenderable(gameObject);

		return gameObject;
	}

};

