#pragma once
class GameObject
{
private:
	int m_xPos;
	int m_yPos;
public:
	GameObject(int xPosition, int yPosition);
	~GameObject();

	void Move(float x, float y);
	int GetXPosition() { return m_xPos; }
	int GetYPosition() { return m_yPos; }
};

