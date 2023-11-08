#pragma once
#include "IGameSystem.h"

class GameSetup : public IGameSystem
{
public:
	bool SetupComplete = false;
	GameSetup();
	~GameSetup();
	//Initialises SDL
	bool init();
	//Frees media and shuts down SDL
	void close();

	// Inherited via IGameSystem
	virtual void Update() override;
	virtual void PreUpdate() override;
	virtual void PostUpdate() override;
};

