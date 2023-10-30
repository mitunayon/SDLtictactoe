#pragma once

class GameSetup
{
public:
	~GameSetup();
	//Initialises SDL
	bool init();
	//Frees media and shuts down SDL
	void close();
};

