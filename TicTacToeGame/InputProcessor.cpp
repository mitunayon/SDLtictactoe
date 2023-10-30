#include "InputProcessor.h"

InputProcessor::InputProcessor()
{
}

InputProcessor::~InputProcessor()
{

}

void InputProcessor::Update()
{
	// Update
	while (GetInputPoll())
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

		//// Image Renderer loop
		//// Set image
		//switch (CurrentInput)
		//{
		//case SDLK_UP:
		//	gImageRenderer->CurrentTexture = gImageRenderer->KeyPressTextures[KEY_PRESS_SURFACE_UP];
		//	break;

		//case SDLK_DOWN:
		//	gImageRenderer->CurrentTexture = gImageRenderer->KeyPressTextures[KEY_PRESS_SURFACE_DOWN];
		//	break;

		//case SDLK_LEFT:
		//	gImageRenderer->CurrentTexture = gImageRenderer->KeyPressTextures[KEY_PRESS_SURFACE_LEFT];
		//	break;

		//case SDLK_RIGHT:
		//	gImageRenderer->CurrentTexture = gImageRenderer->KeyPressTextures[KEY_PRESS_SURFACE_RIGHT];
		//	break;

		//default:
		//	gImageRenderer->CurrentTexture = gImageRenderer->KeyPressTextures[KEY_PRESS_SURFACE_DEFAULT];
		//	break;
		//}
	}
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

bool InputProcessor::GetInputPoll()
{
	return SDL_PollEvent(&m_inputEvent) != 0;
}

bool InputProcessor::IsQuitPressed()
{
	return m_quitGame;
}

