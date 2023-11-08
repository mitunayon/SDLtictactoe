#pragma once
#include "IWorldUpdateObserver.h"
class IWorldUpdatePublisher
{
public:
	virtual ~IWorldUpdatePublisher() {};
	virtual void Attach(IWorldUpdateObserver* observer) = 0;
	virtual void Detach(IWorldUpdateObserver* observer) = 0;
	virtual void Notify() = 0;
};