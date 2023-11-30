#pragma once
#include "IGameSystem.h"
#include "IWorldUpdatePublisher.h"
#include <list>
#include <vector>
#include "GameObject.h"

class World : public IGameSystem, public IWorldUpdatePublisher
{
private :
	std::list<IWorldUpdateObserver*> m_observers;
	std::vector<GameObject*> m_gameObjects;

public:
	World();
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void PostUpdate() override;

	// Inherited via IWorldUpdatePublisher
	void Attach(IWorldUpdateObserver* observer) override;

	void Detach(IWorldUpdateObserver* observer) override;

	void Notify() override;

	void AddGameObject(GameObject* gameObject);

	std::vector<GameObject*>* GetGameObjectsInWorld();

};

