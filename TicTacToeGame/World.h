#pragma once
#include "IGameSystem.h"

class World : public IGameSystem
{
public:
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void PostUpdate() override;
};

