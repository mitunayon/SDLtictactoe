#pragma once
#include <SDL.h>
#include "IGameSystem.h"
#include "IInputPublisher.h"
#include "IInputObserver.h"
#include <list>

class InputProcessor : public IGameSystem, public IInputPublisher
{

private:
	bool m_upPressed;
	bool m_downPressed;
	bool m_leftPressed;
	bool m_rightPressed;
	bool m_quitGame;
	SDL_Event m_inputEvent;

	std::list<IInputObserver*> m_observers;

public:
	InputProcessor();
	~InputProcessor();

	SDL_Keycode CurrentInput;
	void SetCurrentInput(SDL_Keycode keycode);
	bool PollLatestInputEvent();
	bool IsQuitPressed();

	// Inherited via IGameSystem
	virtual void Update() override;
	virtual void PreUpdate() override;
	virtual void PostUpdate() override;

	// Inherited via IInputPublisher
	void Attach(IInputObserver* observer) override;
	void Detach(IInputObserver* observer) override;
	void Notify() override;
};

