#pragma once
class GameObject
{
private:
	float m_xPos;
	float m_yPos;
public:
	GameObject(float xPosition, float yPosition);
	~GameObject();

	void Move(float x, float y);
	float GetXPosition() { return m_xPos; }
	float GetYPosition() { return m_yPos; }
};

class ChildGameObject : public GameObject
{
public:
	ChildGameObject(float xPosition, float yPosition);
};
