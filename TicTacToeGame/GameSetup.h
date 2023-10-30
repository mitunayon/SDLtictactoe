#pragma once

class GameSetup
{
public:
	bool SetupComplete = false;
	GameSetup();
	~GameSetup();
	//Initialises SDL
	bool init();
	//Frees media and shuts down SDL
	void close();
};

