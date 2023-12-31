#include "World.h"

World::World()
{
}

void World::PreUpdate()
{
}

void World::Update()
{
	Notify();
}

void World::PostUpdate()
{
}

void World::Attach(IWorldUpdateObserver* observer)
{
	m_observers.push_back(observer);
}

void World::Detach(IWorldUpdateObserver* observer)
{
	m_observers.remove(observer);
}

void World::Notify()
{
	std::list<IWorldUpdateObserver*>::iterator iterator = m_observers.begin();
	while (iterator != m_observers.end())
	{
		(*iterator)->OnWorldUpdate();
		++iterator;
	}
}

void World::AddGameObject(GameObject* gameObject)
{
	m_gameObjects.push_back(gameObject);
}

std::list<GameObject*>* World::GetGameObjectsInWorld()
{
	return &m_gameObjects;
}
