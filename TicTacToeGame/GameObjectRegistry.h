#pragma once
#include "IGameSystem.h"

class GameObjectRegistry : public IGameSystem
{
public:
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void PostUpdate() override;
};

