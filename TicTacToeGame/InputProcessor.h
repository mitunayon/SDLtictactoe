#pragma once
#include <SDL.h>

class InputProcessor
{

private:
	bool m_upPressed;
	bool m_downPressed;
	bool m_leftPressed;
	bool m_rightPressed;
	bool m_quitGame;
	SDL_Event m_inputEvent;

public:
	InputProcessor();
	~InputProcessor();

	void Update();
	SDL_Keycode CurrentInput;
	void SetCurrentInput(SDL_Keycode keycode);
	bool GetInputPoll();
	bool IsQuitPressed();
};

