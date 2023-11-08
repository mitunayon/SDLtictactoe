#include "InputProcessor.h"

InputProcessor::InputProcessor()
{
}

InputProcessor::~InputProcessor()
{

}

void InputProcessor::Update()
{
	while (PollLatestInputEvent())
	{
		if (m_inputEvent.type == SDL_QUIT)
		{
			m_quitGame = true;
			break;
		}

		if (m_inputEvent.type == SDL_KEYDOWN)
		{
			SDL_Keycode key = m_inputEvent.key.keysym.sym;
			SetCurrentInput(key);
		}
	}

	// Notify subscribers
	Notify();
}

void InputProcessor::PreUpdate()
{
	//Reset Inputs - refactor this to PreUpdate();
	m_upPressed = false;
	m_downPressed = false;
	m_leftPressed = false;
	m_rightPressed = false;
	m_quitGame = false;
}

void InputProcessor::PostUpdate()
{
}

void InputProcessor::Attach(IInputObserver* observer)
{
	m_observers.push_back(observer);
}

void InputProcessor::Detach(IInputObserver* observer)
{
	m_observers.remove(observer);
}

void InputProcessor::Notify()
{
	std::list<IInputObserver*>::iterator iterator = m_observers.begin();
	while (iterator != m_observers.end()) 
	{
		(*iterator)->OnInputUpdate(m_upPressed, m_downPressed, m_leftPressed, m_rightPressed);
		++iterator;
	}
}

void InputProcessor::SetCurrentInput(SDL_Keycode keycode)
{
	CurrentInput = keycode;
	switch (keycode)
	{
	case SDLK_UP:
		m_upPressed = true;
		break;

	case SDLK_DOWN:
		m_downPressed = true;
		break;

	case SDLK_LEFT:
		m_leftPressed = true;
		break;

	case SDLK_RIGHT:
		m_rightPressed = true;
		break;

	default:
		break;
	}
}

bool InputProcessor::PollLatestInputEvent()
{
	return SDL_PollEvent(&m_inputEvent) != 0;
}

bool InputProcessor::IsQuitPressed()
{
	return m_quitGame;
}

