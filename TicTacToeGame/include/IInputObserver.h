#pragma once
class IInputObserver
{
public:
	virtual ~IInputObserver() {};
	virtual void OnInputUpdate(bool upPressed, bool downPressed, bool leftPressed, bool rightPressed) = 0;
};

