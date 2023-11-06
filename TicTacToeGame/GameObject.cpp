#include "GameObject.h"

GameObject::GameObject(int xPosition, int yPosition)
{
	m_xPos = xPosition;
	m_yPos = yPosition;
}

void GameObject::Move(float x, float y)
{
	m_xPos += x;
	m_yPos += y;
}
