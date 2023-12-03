#include "GameObject.h"

GameObject::GameObject(int xPosition, int yPosition, std::string spritePath)
{
	m_xPos = xPosition;
	m_yPos = yPosition;
	m_spritePath = spritePath;
}

GameObject::~GameObject()
{
}

void GameObject::Move(int x, int y)
{
	m_xPos += x;
	m_yPos += y;
}

std::string GameObject::GetSpritePath()
{
	return m_spritePath;
}

BoardGameObject::BoardGameObject(int xPosition, int yPosition, std::string spritePath)
	: GameObject(xPosition, yPosition, spritePath)
{
}

void BoardGameObject::Update()
{
}
