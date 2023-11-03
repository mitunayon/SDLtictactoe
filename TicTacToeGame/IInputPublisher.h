#pragma once
#include "IInputObserver.h"
class IInputPublisher
{
public:
	virtual ~IInputPublisher() {};
	virtual void Attach(IInputObserver* observer) = 0;
	virtual void Detach(IInputObserver* observer) = 0;
	virtual void Notify() = 0;
};

