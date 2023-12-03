#pragma once
#include <string>

class GameObject
{
private:
	int m_xPos;
	int m_yPos;

protected:
	std::string m_spritePath;
	virtual void Update() = 0;

public:
	GameObject(int xPosition, int yPosition, std::string m_spritePath);
	~GameObject();

	void Move(int x, int y);
	int GetXPosition() { return m_xPos; }
	int GetYPosition() { return m_yPos; }

	// Returns the sprite asset path
	std::string GetSpritePath();
};

class BoardGameObject : public GameObject
{
public:
	BoardGameObject(int xPosition, int yPosition, std::string spritePath);

	// Inherited via GameObject
	virtual void Update() override;
};
