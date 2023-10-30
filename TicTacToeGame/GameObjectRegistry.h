#pragma once
#include "IGameSystem.h"

class GameObjectRegistry : public IGameSystem
{
public:
	virtual void PreUpdate();
	virtual void Update();
	virtual void PostUpdate();
};

