#pragma once
#include <string>
#include "Vector2.h"

class GameObject
{
private:
	Vector2 m_position;

protected:
	const std::string m_spritePath;
	virtual void Update() = 0;

public:
	GameObject(int xPosition, int yPosition, std::string m_spritePath);
	~GameObject();

	void Move(int x, int y);
	Vector2& GetPosition() { return m_position; }

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
