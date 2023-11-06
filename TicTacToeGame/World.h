#pragma once
#include "IGameSystem.h"
#include "IWorldUpdatePublisher.h"

class World : public IGameSystem, public IWorldUpdatePublisher
{
public:
	virtual void PreUpdate() override;
	virtual void Update() override;
	virtual void PostUpdate() override;

	// Inherited via IWorldUpdatePublisher
	void Attach(IWorldUpdateObserver* observer) override;

	void Detach(IWorldUpdateObserver* observer) override;

	void Notify() override;

};

