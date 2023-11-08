#include "GameObject.h"

GameObject::GameObject(float xPosition, float yPosition)
{
	m_xPos = xPosition;
	m_yPos = yPosition;
}

GameObject::~GameObject()
{
}

void GameObject::Move(float x, float y)
{
	m_xPos += x;
	m_yPos += y;
}

ChildGameObject::ChildGameObject(float xPosition, float yPosition)
	: GameObject(xPosition, yPosition)
{
}
