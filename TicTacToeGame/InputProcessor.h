#pragma once
#include <SDL.h>
#include "IGameSystem.h"

class InputProcessor : public IGameSystem
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

	SDL_Keycode CurrentInput;
	void SetCurrentInput(SDL_Keycode keycode);
	bool GetInputPoll();
	bool IsQuitPressed();

	// Inherited via IGameSystem
	virtual void Update() override;
	virtual void PreUpdate() override;
	virtual void PostUpdate() override;
};

